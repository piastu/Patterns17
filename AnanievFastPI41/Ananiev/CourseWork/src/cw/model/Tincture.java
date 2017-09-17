package cw.model;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.util.HashMap;
import java.util.List;
import java.util.Random;

import cw.gui.form.FieldData;
import cw.gui.form.FieldData.Type;

// Класс, описывающий настойку
public class Tincture extends AbstractMeans {
	
	private int volume = 0;
	private String conditions = null;
	
	public Tincture() {
		super();
		icon = (new Random()).nextInt(8);
	}
	
	@Override
	public void addFormFields(List<FieldData> list) {
		super.addFormFields(list);
		list.add(new FieldData("volume",     "Объём (мл)",       Type.INT,  false, volume));
		list.add(new FieldData("conditions", "Условия хранения", Type.TEXT, true,  conditions));
	}

	@Override
	public void acceptValues(HashMap<String, Object> map) {
		super.acceptValues(map);
		volume = (int)map.get("volume");
		conditions = (String)map.get("conditions");
	}
	
	@Override
	public String getIconLocation() {
		return "/resources/tincture/" + icon + ".png";
	}
	
	@Override
	public void writeToFile(DataOutputStream out) throws Exception {
		super.writeToFile(out);
		out.writeInt(volume);
		out.writeUTF(conditions);
	}
	
	@Override
	public void readFromFile(DataInputStream in) throws Exception {
		super.readFromFile(in);
		volume = in.readInt();
		conditions = in.readUTF();
	}

}
