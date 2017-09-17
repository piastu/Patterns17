package cw.model;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import cw.ISaveable;
import cw.Main;
import cw.gui.form.FieldData;
import cw.gui.form.FieldData.Type;
import cw.gui.form.IEditable;

// Класс, описывающий болезнь
public class Disease implements IEditable, ISaveable {
	
	private static int maxId = 0;
	private int id;
	
	private String name = null, sympthoms = null, effects = null;
	private ArrayList<Integer> methods = new ArrayList<Integer>();
	
	private boolean selected = false;
	
	public Disease() {
		id = maxId++;
	}
	
	public ArrayList<AbstractMeans> getSelectedMeans() {
		ArrayList<AbstractMeans> list = new ArrayList<AbstractMeans>();
		AbstractMeans[][] m = Main.getMeans();
		for(int i = 0; i < m.length; i++)
			for(int j = 0; j < m[i].length; j++)
				if(m[i][j] != null && methods.contains(m[i][j].getId())) list.add(m[i][j]);
		return list;
	}
	
	public int getId() {
		return id;
	}
	
	public boolean isUseMean(AbstractMeans m) {
		return methods.contains(m.getId());
	}
	
	public boolean isPositive() {
		int positive = 0, negative = 0;
		for(Patient p : Main.getMainFrame().getPatientsAsList())
			if(p.isIll(this)) {
				if(p.getResult() > 0) positive++;
				if(p.getResult() < 0) negative++;
			}
		return positive > negative;
	}
	
	public void setSelected(boolean s) {
		selected = s;
	}
	
	@Override
	public void addFormFields(List<FieldData> list) {
		list.add(new FieldData("name",      "Название болезни", Type.STRING,       false, name));
		list.add(new FieldData("sympthoms", "Симптомы",         Type.TEXT,         false, sympthoms));
		list.add(new FieldData("effects",   "Последствия",      Type.TEXT,         false, effects));
		list.add(new FieldData("methods",   "Методы лечения",   Type.MULTI_SELECT, false, getSelectedMeans(), Main.getMeansAsList()));
	}
	
	@Override
	@SuppressWarnings("unchecked")
	public void acceptValues(HashMap<String, Object> map) {
		name = (String)map.get("name");
		sympthoms = (String)map.get("sympthoms");
		effects = (String)map.get("effects");
		
		methods.clear();
		for(AbstractMeans m : (List<AbstractMeans>)map.get("methods")) methods.add(m.getId());
	}
	
	@Override
	public String toString() {
		return !selected ? name : "<html><b>" + name + "</b></html>";
	}
	
	@Override
	public void writeToFile(DataOutputStream out) throws Exception {
		out.writeInt(id); if(id > maxId) maxId = id + 1;
		out.writeUTF(name);
		out.writeUTF(sympthoms);
		out.writeUTF(effects);
		
		out.writeInt(methods.size());
		for(Integer i : methods) out.writeInt(i);
	}

	@Override
	public void readFromFile(DataInputStream in) throws Exception {
		id = in.readInt();
		name = in.readUTF();
		sympthoms = in.readUTF();
		effects = in.readUTF();
		
		int size = in.readInt();
		for(int i = 0; i < size; i++) methods.add(in.readInt());
	}
	
}
