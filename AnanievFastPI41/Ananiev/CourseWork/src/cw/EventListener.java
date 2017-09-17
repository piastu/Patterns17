package cw;

import java.awt.Component;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.util.ArrayList;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

import cw.gui.MainFrame;
import cw.gui.form.FormBuilder;
import cw.gui.form.FormBuilder.FormType;
import cw.model.*;

// Обработчик событий, приходящих от основной формы
public class EventListener implements ActionListener {

	@Override
	public void actionPerformed(ActionEvent e) {
		MainFrame frame = Main.getMainFrame();
		switch(e.getActionCommand()) {
			case "menu-exit":
				System.exit(0);
				break;
			case "disease-selection":
			case "patient-selection":
				onListSelectionChanged((JList<?>)e.getSource());
				break;
			case "disease-add":
				Disease d = new FormBuilder<Disease>(new Disease(), FormType.NEW).show();
				if(d != null) Main.getMainFrame().getDiseases().addElement(d);
				break;
			case "disease-edit":
				Disease o = new FormBuilder<Disease>(frame.getDiseases().getElementAt(frame.getDiseasesList().getSelectedIndex()), FormType.EDIT).show();
				if(o != null) frame.getDiseasesList().repaint();
				break;
			case "disease-remove":
				if(confirmDelete()) frame.getDiseases().remove(frame.getDiseasesList().getSelectedIndex());
				break;
			case "patient-add":	
				Patient p = new FormBuilder<Patient>(new Patient(), FormType.NEW).show();
				if(p != null) Main.getMainFrame().getPatients().addElement(p);
				break;
			case "patient-edit":
				Patient a = new FormBuilder<Patient>(frame.getPatients().getElementAt(frame.getPatientsList().getSelectedIndex()), FormType.EDIT).show();
				if(a != null) frame.getPatientsList().repaint();
				break;
			case "patient-remove":
				if(confirmDelete()) frame.getPatients().remove(frame.getPatientsList().getSelectedIndex());
				break;
			case "menu-save":
				File f = Main.getFile() != null ? Main.getFile() : Main.getFileIO().getSaveFile();
				if(f != null) {
					Main.getFileIO().saveToFile(f);
					Main.setFile(f);
				}
				break;
			case "menu-save-as":
				File save = Main.getFileIO().getSaveFile();
				if(save != null) {
					Main.getFileIO().saveToFile(save);
					Main.setFile(save);
				}
				break;
			case "menu-load":
				File load = Main.getFileIO().getOpenFile();
				if(load != null)
					if(Main.getFileIO().readFromFile(load)) {
						Main.setFile(load);
					} else {
						JOptionPane.showMessageDialog(Main.getMainFrame(), "При чтении выбранного файла возникла ошибка!", "Ошибка", JOptionPane.ERROR_MESSAGE);
					}
				break;
			case "work-positive":
			case "work-negative":
				DefaultListModel<Patient> list = Main.getMainFrame().getPatients();
				for(int i = 0; i < list.size(); i++) {
					Patient pa = list.getElementAt(i);
					pa.setSelected(false);
					if(pa.getResult() > 0 && e.getActionCommand().endsWith("-positive")) pa.setSelected(true);
					if(pa.getResult() < 0 && e.getActionCommand().endsWith("-negative")) pa.setSelected(true);
				}
				Main.getMainFrame().getPatientsList().repaint();
				break;
			case "work-means":
				ArrayList<AbstractMeans> popular = new ArrayList<AbstractMeans>();
				int pop = 0;
				for(AbstractMeans m : Main.getMeansAsList()) {
					int u = m.getUsesCount();
					if(popular.isEmpty() || pop < u) {
						popular.clear();
						popular.add(m);
						pop = u;
					} else if(pop == u) {
						popular.add(m);
					}
					m.setSelected(false);
				}
				for(AbstractMeans m : popular) m.setSelected(true);
				Main.getMainFrame().getShelves().repaint();
				break;
			case "work-diseases":
				DefaultListModel<Disease> dis = Main.getMainFrame().getDiseases();
				for(int i = 0; i < dis.size(); i++)
					dis.getElementAt(i).setSelected(dis.getElementAt(i).isPositive());
				Main.getMainFrame().getDiseasesList().repaint();
				break;
			case "work-reset":
				DefaultListModel<Patient> l = Main.getMainFrame().getPatients();
				for(int i = 0; i < l.size(); i++) l.getElementAt(i).setSelected(false);
				DefaultListModel<Disease> j = Main.getMainFrame().getDiseases();
				for(int i = 0; i < j.size(); i++) j.getElementAt(i).setSelected(false);
				for(AbstractMeans m : Main.getMeansAsList()) m.setSelected(false);
				Main.getMainFrame().repaint();
				break;
			default:
				System.out.println(e.getActionCommand());
		}
	}
	
	public void onCanvasClick(int x, int y) {
		if(Main.getMeans()[x][y] == null) {
			String[] options = new String[] {"Травяной сбор", "Настойка"};
			String selected = (String) JOptionPane.showInputDialog(Main.getMainFrame(), "Выберите тип добавляемого средства", "Добавление средства", 
					JOptionPane.QUESTION_MESSAGE, null, options, options[0]);
			if(selected != null) {
				AbstractMeans m = null;
				if(selected.equals(options[1])) {
					m = new FormBuilder<Tincture>(new Tincture(), FormType.NEW).show();
				} else {
					m = new FormBuilder<Herbal>(new Herbal(), FormType.NEW).show();
				}
				
				if(m != null) {
					m.setLocation(x, y);
					Main.getMeans()[x][y] = m;
					Main.getMainFrame().getShelves().reloadSlot(x, y);
				}
			}
		} else {
			Object o = new FormBuilder<AbstractMeans>(Main.getMeans()[x][y], FormType.EDIT_DELETE).show();
			if(o == null) {
				Main.getMeans()[x][y] = null;
				Main.getMainFrame().getShelves().reloadSlot(x, y);
			}
		}
	}
	
	private void onListSelectionChanged(JList<?> list) {
		JPanel buttonsPanel = (JPanel)list.getParent().getParent().getParent().getComponents()[1];
		for(Component c : buttonsPanel.getComponents())
			if(c instanceof JButton) {
				JButton b = (JButton)c;
				if(b.getActionCommand().endsWith("-edit") || b.getActionCommand().endsWith("-remove"))
					b.setEnabled(list.getSelectedIndex() != -1);
			}
	}
	
	public static boolean confirmDelete() {
		return JOptionPane.showConfirmDialog(Main.getMainFrame(), "Вы действительно хотите удалить запись?", "Подтверждение", JOptionPane.YES_NO_OPTION) == JOptionPane.YES_OPTION;
	}
	
}
