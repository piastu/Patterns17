package cw.gui.form;

import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JDialog;
import javax.swing.JFormattedTextField;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSeparator;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.ListSelectionModel;
import javax.swing.SwingConstants;
import javax.swing.UIManager;
import javax.swing.text.NumberFormatter;

import cw.Main;
import cw.gui.Utils;
import cw.gui.form.FieldData.Type;

// Построитель форм на основе переданных от объекта данных
public class FormBuilder<T extends IEditable> implements ActionListener {
	
	public static enum FormType { NEW, EDIT, EDIT_DELETE }
	
	private T object;
	private ArrayList<FieldData> data;
	private FormType curType;
	
	private JDialog frame;
	private HashMap<String, Component> components = new HashMap<String, Component>();
	
	public FormBuilder(T o, FormType type) {
		data = new ArrayList<FieldData>();
		object = o;
		object.addFormFields(data);
		curType = type;
		createNewDialog();
	}
	
	private void createNewDialog() {
		frame = new JDialog(Main.getMainFrame(), curType != FormType.NEW ? "Редактирование записи" : "Добавление записи", true);
		frame.getContentPane().setLayout(new BoxLayout(frame.getContentPane(), BoxLayout.PAGE_AXIS));
		frame.add(Box.createRigidArea(new Dimension(0, 2)));
		
		for(FieldData d : data) {
			frame.add(Box.createRigidArea(new Dimension(0, 3)));
			frame.add(getFieldPanel(d));
		}
		
		frame.add(Box.createRigidArea(new Dimension(0, 11)));
		JSeparator s = new JSeparator(SwingConstants.HORIZONTAL);
		s.setMaximumSize(new Dimension(s.getMaximumSize().width, 6));
		frame.add(s);
		
		JPanel buttons = new JPanel();
		buttons.setLayout(new BoxLayout(buttons, BoxLayout.LINE_AXIS));
		
		JButton save = new JButton(curType != FormType.NEW ? "Сохранить" : "Добавить");
		Utils.setFixedSize(save, curType != FormType.EDIT_DELETE ? 100 : 90, 26);
		save.addActionListener(this);
		save.setActionCommand("save");
		buttons.add(save);
		
		buttons.add(Box.createRigidArea(new Dimension(8, 0)));
		
		if(curType == FormType.EDIT_DELETE) {
			JButton delete = new JButton("Удалить");
			Utils.setFixedSize(delete, 90, 26);
			delete.addActionListener(this);
			delete.setActionCommand("delete");
			buttons.add(delete);
			
			buttons.add(Box.createRigidArea(new Dimension(8, 0)));
		}
		
		JButton cancel = new JButton("Отмена");
		Utils.setFixedSize(cancel, curType != FormType.EDIT_DELETE ? 100 : 90, 26);
		cancel.addActionListener(this);
		cancel.setActionCommand("cancel");
		buttons.add(cancel);
		frame.add(buttons);
		
		frame.pack();
		Utils.setFrameFavicon(frame, "/resources/edit.png");
		frame.setResizable(false);
		frame.setLocationRelativeTo(Main.getMainFrame());
		frame.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent event) {
				if(curType != FormType.EDIT_DELETE) object = null;
			}
		});
	}
	
	public T show() {
		frame.setVisible(true);
		return object;
	}
	
	private JPanel getFieldPanel(FieldData data) {
		JPanel panel = new JPanel();
		panel.setLayout(new BoxLayout(panel, BoxLayout.LINE_AXIS));
		
		JLabel l = new JLabel(data.getName() + ":");
		Utils.setFixedSize(l, 105, 22);
		l.setAlignmentY(Component.TOP_ALIGNMENT);
		l.setBorder(BorderFactory.createEmptyBorder(0, 3, 0, 0));
		panel.add(l);
		
		JComponent c = null;
		switch(data.getType()) {
			case STRING:
				JTextField f = new JTextField();
				Utils.setFixedSize(f, 180, 22);
				if(data.getDefaultValue() != null) f.setText((String)data.getDefaultValue());
				c = f;
				break;
			case INT:
				NumberFormatter numberFormatter = new NumberFormatter(NumberFormat.getIntegerInstance());
				numberFormatter.setValueClass(Integer.class);
				numberFormatter.setMinimum(0);
				JFormattedTextField field = new JFormattedTextField(numberFormatter);
				Utils.setFixedSize(field, 180, 22);
				if(data.getDefaultValue() != null) field.setValue(data.getDefaultValue());
				c = field;
				break;
			case TEXT:
				JTextArea area = new JTextArea();
				area.setFont(new JLabel().getFont());
				c = wrapToScroll(area, 48);
				if(data.getDefaultValue() != null) area.setText((String)data.getDefaultValue());
				break;
			case SINGLE_SELECT:
			case MULTI_SELECT:
				JList<Object> list = new JList<Object>(data.getItemsForSelect());
				if(data.getType() == Type.SINGLE_SELECT) {
					list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
					list.setSelectedIndex((int)data.getDefaultValue());
				} else {
					int[] selectedIndexes = new int[0];
					for(int i = 0; i < list.getModel().getSize(); i++)
						if(((ArrayList<?>)data.getDefaultValue()).contains(list.getModel().getElementAt(i))) selectedIndexes = Utils.addToIntArray(selectedIndexes, i);
					list.setSelectedIndices(selectedIndexes);
				}
				c = wrapToScroll(list, data.getType() == Type.SINGLE_SELECT ? 50 : 80);
				break;
			case DATE:
			case TIME:
				JFormattedTextField date = new JFormattedTextField(Utils.getDateFormat(data.getType() == Type.TIME));
				Utils.setFixedSize(date, 180, 22);
				date.setValue((data.getDefaultValue() != null) ? data.getDefaultValue() : new Date(data.getType() == Type.DATE ? 0 : System.currentTimeMillis()));
				c = date;
				break;
			default:
				return panel;
		}
		if(c != null) {
			panel.add(c);
			c.setAlignmentY(Component.TOP_ALIGNMENT);
			components.put(data.getKey(), c);
		}
		return panel;
	}
	
	private JScrollPane wrapToScroll(Component c, int height) {
		JScrollPane scroll = new JScrollPane(c);
		Utils.setFixedSize(scroll, 180, height);
		scroll.setBorder(BorderFactory.createLineBorder(UIManager.getColor("activeCaptionBorder")));
		return scroll;
	}
	
	@Override
	@SuppressWarnings({ "unchecked", "rawtypes" })
	public void actionPerformed(ActionEvent e) {
		if(e.getActionCommand().equals("cancel")) {
			frame.setVisible(false);
			if(curType != FormType.EDIT_DELETE) object = null;
		} else if(e.getActionCommand().equals("delete")) {
			frame.setVisible(false);
			object = null;
		} else {
			boolean exit = true;
			HashMap<String, Object> result = new HashMap<String, Object>();
			
			for(FieldData d : data) {
				boolean error = false;
				
				switch(d.getType()) {
					case STRING:
						String str = ((JTextField)getComponent(d.getKey())).getText().trim();
						result.put(d.getKey(), str);
						if(!d.allowEmpty() && str.equals("")) error = true;
						break;
					case INT:
						Object o = ((JFormattedTextField)getComponent(d.getKey())).getValue();
						result.put(d.getKey(), (int)o);
						if(!d.allowEmpty() && o == null) error = true;
						break;
					case TEXT:
						String text = ((JTextArea)getComponent(d.getKey())).getText().trim();
						result.put(d.getKey(), text);
						if(!d.allowEmpty() && text.equals("")) error = true;
						break;
					case SINGLE_SELECT:
						int i = ((JList)getComponent(d.getKey())).getSelectedIndex();
						result.put(d.getKey(), i);
						if(!d.allowEmpty() && i == -1) error = true;
						break;
					case MULTI_SELECT:
						List<Object> list = ((JList)getComponent(d.getKey())).getSelectedValuesList();
						result.put(d.getKey(), list);
						if(!d.allowEmpty() && list.isEmpty()) error = true;
						break;
					case DATE:
					case TIME:
						Object s = ((JFormattedTextField)getComponent(d.getKey())).getValue();
						result.put(d.getKey(), (Date)s);
						break;
					default: 
				}
				
				getComponent(d.getKey()).setBackground(new Color(error ? 0xF4E6E6 : 0xFFFFFF));
				if(error) exit = false;
			}
			if(exit) {
				object.acceptValues(result);
				frame.setVisible(false);
			}
		}
	}
	
	private Component getComponent(String key) {
		Component o = components.get(key);
		if(o instanceof JScrollPane) return ((JScrollPane)o).getViewport().getView();
		return o;
	}
	
}
