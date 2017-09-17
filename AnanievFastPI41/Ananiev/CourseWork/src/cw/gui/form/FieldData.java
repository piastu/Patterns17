package cw.gui.form;

import java.util.List;

import javax.swing.DefaultListModel;
import javax.swing.ListModel;

// Класс-описание поля для построителя форм
public class FieldData {
	
	public static enum Type { STRING, INT, TEXT, SINGLE_SELECT, MULTI_SELECT, DATE, TIME }
	
	private String key, name;
	private Type type;
	private boolean empty;
	
	private Object def;
	private List<?> select = null;
	
	public FieldData(String k, String n, Type t, boolean e, Object d) {
		key = k;
		name = n;
		type = t;
		empty = e;
		def = d;
	}
	
	public FieldData(String k, String n, Type t, boolean e, Object d, List<?> a) {
		this(k, n, t, e, d);
		select = a;
	}
	
	public String getKey() {
		return key;
	}
	
	public String getName() {
		return name;
	}
	
	public Type getType() {
		return type;
	}
	
	public boolean allowEmpty() {
		return empty;
	}
	
	public Object getDefaultValue() {
		return def;
	}
	
	public ListModel<Object> getItemsForSelect() {
		DefaultListModel<Object> model = new DefaultListModel<Object>();
		for(Object o : select) model.addElement(o);
		return model;
	}
	
}
