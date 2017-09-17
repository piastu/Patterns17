package cw.model;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.HashMap;
import java.util.List;

import cw.ISaveable;
import cw.Main;
import cw.gui.Utils;
import cw.gui.form.FieldData;
import cw.gui.form.IEditable;
import cw.gui.form.FieldData.Type;

// Класс, описывающий пациента
public class Patient implements IEditable, ISaveable {
	
	private static final String[] results = new String[]{ "Неизвестно", "Положительные", "Отрицательные" };
	
	private String surname = null, name = null, patronymic = null, notes = null;
	private Date birthday = null, time = null;
	private ArrayList<Integer> diseases = new ArrayList<Integer>();
	private int result = 0;
	
	private boolean selected = false;
	
	public int getResult() {
		if(result == 2) return -1;
		return result;
	}
	
	public ArrayList<Disease> getSelectedDiseases() {
		ArrayList<Disease> list = new ArrayList<Disease>();
		for(Disease d : Main.getMainFrame().getDiseasesAsList())
			if(diseases.contains(d.getId())) list.add(d);
		return list;
	}
	
	public void setSelected(boolean s) {
		selected = s;
	}
	
	public boolean isIll(Disease d) {
		return diseases.contains(d.getId());
	}
	
	@Override
	public void addFormFields(List<FieldData> list) {
		list.add(new FieldData("surname",    "Фамилия",       Type.STRING,        false, surname));
		list.add(new FieldData("name",       "Имя",           Type.STRING,        false, name));
		list.add(new FieldData("patronymic", "Отчество",      Type.STRING,        false, patronymic));
		list.add(new FieldData("birthday",   "Дата рождения", Type.DATE,          false, birthday));
		list.add(new FieldData("time",       "Время приёма",  Type.TIME,          false, time));
		list.add(new FieldData("diseases",   "Заболевания",   Type.MULTI_SELECT,  false, getSelectedDiseases(), Main.getMainFrame().getDiseasesAsList()));
		list.add(new FieldData("result",     "Результаты",    Type.SINGLE_SELECT, false, result, Arrays.asList(results)));
		list.add(new FieldData("notes",      "Примечания",    Type.TEXT,          true,  notes));
	}

	@Override
	@SuppressWarnings("unchecked")
	public void acceptValues(HashMap<String, Object> map) {
		surname = (String)map.get("surname");
		name = (String)map.get("name");
		patronymic = (String)map.get("patronymic");
		birthday = (Date)map.get("birthday");
		time = (Date)map.get("time");
		notes = (String)map.get("notes");
		result = (int)map.get("result");
		
		diseases.clear();
		for(Disease m : (List<Disease>)map.get("diseases")) diseases.add(m.getId());
	}
	
	@Override
	public String toString() {
		String date = "[" + Utils.getDateFormat(true).format(time) + "] ";
		String data = surname + " " + name + " " + patronymic;
		return !selected ? date + data : "<html>" + date + "<b>" + data + "</b></html>";
	}

	@Override
	public void writeToFile(DataOutputStream out) throws Exception {
		out.writeUTF(surname);
		out.writeUTF(name);
		out.writeUTF(patronymic);
		out.writeUTF(notes);
		
		out.writeLong(birthday.getTime());
		out.writeLong(time.getTime());
		
		out.writeInt(result);
		
		out.writeInt(diseases.size());
		for(Integer i : diseases) out.writeInt(i);
	}

	@Override
	public void readFromFile(DataInputStream in) throws Exception {
		surname = in.readUTF();
		name = in.readUTF();
		patronymic = in.readUTF();
		notes = in.readUTF();
		
		birthday = new Date(in.readLong());
		time = new Date(in.readLong());
		
		result = in.readInt();
		
		int size = in.readInt();
		for(int i = 0; i < size; i++) diseases.add(in.readInt());
	}
	
}
