package cw.model;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.util.HashMap;
import java.util.List;

import cw.ISaveable;
import cw.Main;
import cw.gui.form.FieldData;
import cw.gui.form.IEditable;
import cw.gui.form.FieldData.Type;

// Абстрактный класс, описывающий способ лечения
public abstract class AbstractMeans implements IEditable, ISaveable {
	
	private static int maxId = 0;
	
	protected int icon, x, y, id;
	protected String name = null, instruction = null;
	
	private boolean selected = false;
	
	public AbstractMeans() {
		id = maxId++;
	}
	
	public int getId() {
		return id;
	}
	
	public void setLocation(int xPos, int yPos) {
		x = xPos;
		y = yPos;
	}
	
	public int getX() {
		return x;
	}
	
	public int getY() {
		return y;
	}
	
	public int getUsesCount() {
		int counter = 0;
		for(Disease d : Main.getMainFrame().getDiseasesAsList())
			if(d.isUseMean(this)) counter++;
		return counter;
	}
	
	public void setSelected(boolean s) {
		selected = s;
	}
	
	public boolean isSelected() {
		return selected;
	}
	
	@Override
	public void addFormFields(List<FieldData> list) {
		list.add(new FieldData("name",        "Название",   Type.STRING, false, name));
		list.add(new FieldData("instruction", "Инструкция", Type.TEXT,   false, instruction));
	}
	
	@Override
	public void acceptValues(HashMap<String, Object> map) {
		name = (String)map.get("name");
		instruction = (String)map.get("instruction");
	}
	
	@Override
	public String toString() {
		return name;
	}
	
	@Override
	public void writeToFile(DataOutputStream out) throws Exception {
		out.writeInt(icon);
		out.writeInt(x);
		out.writeInt(y);
		out.writeInt(id);
		
		out.writeUTF(name);
		out.writeUTF(instruction);
	}
	
	@Override
	public void readFromFile(DataInputStream in) throws Exception {
		icon = in.readInt();
		x = in.readInt();
		y = in.readInt();
		id = in.readInt(); if(id > maxId) maxId = id + 1;
		
		name = in.readUTF();
		instruction = in.readUTF();
	}
	
	public abstract String getIconLocation();
	
}
