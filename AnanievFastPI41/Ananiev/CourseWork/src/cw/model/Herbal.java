package cw.model;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.util.HashMap;
import java.util.List;
import java.util.Random;

import cw.gui.form.FieldData;
import cw.gui.form.FieldData.Type;

// Класс, описывающий травяной сбор
public class Herbal extends AbstractMeans {
	
	private int weight = 0;
	private String composition = null;
	
	public Herbal() {
		super();
		icon = (new Random()).nextInt(22);
	}
	
	@Override
	public void addFormFields(List<FieldData> list) {
		super.addFormFields(list);
		list.add(new FieldData("weight",      "Вес (гр)",     Type.INT,  false, weight));
		list.add(new FieldData("composition", "Составляющие", Type.TEXT, false, composition));
	}

	@Override
	public void acceptValues(HashMap<String, Object> map) {
		super.acceptValues(map);
		weight = (int)map.get("weight");
		composition = (String)map.get("composition");
	}
	
	@Override
	public String getIconLocation() {
		return "/resources/herbal/" + icon + ".png";
	}
	
	@Override
	public void writeToFile(DataOutputStream out) throws Exception {
		super.writeToFile(out);
		out.writeInt(weight);
		out.writeUTF(composition);
	}
	
	@Override
	public void readFromFile(DataInputStream in) throws Exception {
		super.readFromFile(in);
		weight = in.readInt();
		composition = in.readUTF();
	}
	
}