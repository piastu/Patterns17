package cw.gui.form;

import java.util.HashMap;
import java.util.List;

// Интерфейс для описания объекта, по которому может быть построена форма
public interface IEditable {
	
	public void addFormFields(List<FieldData> list);
	
	public void acceptValues(HashMap<String, Object> map);
	
}
