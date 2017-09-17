package cw.gui;

import java.awt.BorderLayout;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.ArrayList;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.KeyStroke;
import javax.swing.ListSelectionModel;
import javax.swing.ScrollPaneConstants;
import javax.swing.UIManager;
import javax.swing.border.CompoundBorder;
import javax.swing.border.TitledBorder;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

import cw.Main;
import cw.model.Disease;
import cw.model.Patient;

// Класс основной формы приложения
@SuppressWarnings("serial")
public class MainFrame extends JFrame {
	
	private JList<Disease> diseases;
	private JList<Patient> patients;
	private Shelves shelves;
	
	public MainFrame() {
		super("Справочник знахаря");
		
		Utils.setFixedSize(this, 650, 405);
		this.setJMenuBar(createMenu());
		this.setLayout(new GridBagLayout());
		((JPanel)this.getContentPane()).setBorder(BorderFactory.createEmptyBorder(4, 4, 4, 4));
		
		diseases = new JList<Disease>(new DefaultListModel<Disease>());
		this.add(wrapListToPanel(diseases, "Болезни", "disease"), Utils.getGridPosition(0, 0, 1, 1, new Insets(0, 0, 0, 2)));
		
		patients = new JList<Patient>(new DefaultListModel<Patient>());
		this.add(wrapListToPanel(patients, "Пациенты", "patient"), Utils.getGridPosition(1, 0, 1, 1, new Insets(0, 1, 0, 0)));
		
		shelves = new Shelves();
		this.add(shelves, Utils.getGridPosition(0, 1, 2, 1, new Insets(0, 0, 0, 0)));
		
		Utils.setFrameFavicon(this, "/resources/favicon.png");
		this.setResizable(false);
		this.setLocationRelativeTo(null);
		
		this.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent event) {
				System.exit(0);
			}
		});
	}
	
	public JList<Disease> getDiseasesList() {
		return diseases;
	}
	
	public DefaultListModel<Disease> getDiseases() {
		return (DefaultListModel<Disease>)diseases.getModel();
	}
	
	public ArrayList<Disease> getDiseasesAsList() {
		ArrayList<Disease> list = new ArrayList<Disease>();
		for(int i = 0; i < getDiseases().getSize(); i++)
			list.add(getDiseases().getElementAt(i));
		return list;
	}
	
	public void loadDiseases(ArrayList<Disease> a) {
		getDiseases().clear();
		for(Disease d : a) getDiseases().addElement(d);
	}
	
	public JList<Patient> getPatientsList() {
		return patients;
	}
	
	public DefaultListModel<Patient> getPatients() {
		return (DefaultListModel<Patient>)patients.getModel();
	}
	
	public ArrayList<Patient> getPatientsAsList() {
		ArrayList<Patient> list = new ArrayList<Patient>();
		for(int i = 0; i < getPatients().getSize(); i++)
			list.add(getPatients().getElementAt(i));
		return list;
	}
	
	public void loadPatients(ArrayList<Patient> a) {
		getPatients().clear();
		for(Patient p : a) getPatients().addElement(p);
	}
	
	public Shelves getShelves() {
		return shelves;
	}
	
	private JMenuBar createMenu() {
		JMenuBar menuBar = new JMenuBar();
		
		JMenuItem load = new JMenuItem("Загрузить данные");
		load.addActionListener(Main.getEventListener());
		load.setActionCommand("menu-load");
	
		JMenuItem save = new JMenuItem("Сохранить");
		save.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S, ActionEvent.CTRL_MASK));
		save.addActionListener(Main.getEventListener());
		save.setActionCommand("menu-save");
		
		JMenuItem saveAs = new JMenuItem("Сохранить как...");
		saveAs.addActionListener(Main.getEventListener());
		saveAs.setActionCommand("menu-save-as");
		
		JMenuItem exit = new JMenuItem("Выйти");
		exit.addActionListener(Main.getEventListener());
		exit.setActionCommand("menu-exit");
		
		JMenu file = new JMenu("Файл");
		file.add(load);
		file.add(save);
		file.add(saveAs);
		file.addSeparator();
		file.add(exit);
		menuBar.add(file);
		
		JMenuItem positive = new JMenuItem("Положительные результаты");
		positive.addActionListener(Main.getEventListener());
		positive.setActionCommand("work-positive");
		
		JMenuItem negative = new JMenuItem("Отрицательные результаты");
		negative.addActionListener(Main.getEventListener());
		negative.setActionCommand("work-negative");
		
		JMenuItem means = new JMenuItem("Наиболее популярные средства");
		means.addActionListener(Main.getEventListener());
		means.setActionCommand("work-means");
		
		JMenuItem diseases = new JMenuItem("Болезни с положительными исходами");
		diseases.addActionListener(Main.getEventListener());
		diseases.setActionCommand("work-diseases");
		
		JMenuItem reset = new JMenuItem("Сбросить выделение");
		reset.addActionListener(Main.getEventListener());
		reset.setActionCommand("work-reset");
		
		JMenu work = new JMenu("Обработка данных");
		work.add(positive);
		work.add(negative);
		work.addSeparator();
		work.add(means);
		work.addSeparator();
		work.add(diseases);
		work.addSeparator();
		work.add(reset);
		menuBar.add(work);
		
		return menuBar;
	}
	
	private JPanel wrapListToPanel(final JList<?> list, String title, final String eventPrefix) {
		list.setBorder(BorderFactory.createEmptyBorder(2, 3, 2, 3));
		list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		list.addListSelectionListener(new ListSelectionListener() {
			@Override
			public void valueChanged(ListSelectionEvent e) {
				if(e.getValueIsAdjusting()) return;
				ActionEvent a = new ActionEvent(list, ActionEvent.ACTION_PERFORMED, eventPrefix + "-selection");
				Main.getEventListener().actionPerformed(a);
			}
		});
		
		JScrollPane scroll = new JScrollPane(list);
		scroll.setBorder(new CompoundBorder(BorderFactory.createEmptyBorder(2, 2, 2, 2), BorderFactory.createLineBorder(UIManager.getColor("InternalFrame.borderLight"))));
		scroll.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
		
		JPanel panel = new JPanel();
		Utils.setFixedSize(panel, 316, 272);
		panel.setLayout(new BorderLayout(0, 3));
		panel.setBorder(new TitledBorder(title));
		panel.add(scroll, BorderLayout.CENTER);
		panel.add(createControlButtons(eventPrefix), BorderLayout.PAGE_END);
		return panel;
	}
	
	private JPanel createControlButtons(String eventPrefix) {
		JPanel panel = new JPanel();
		panel.setLayout(new BoxLayout(panel, BoxLayout.LINE_AXIS));
		panel.add(Box.createHorizontalGlue());
		
		JButton add = new JButton("Добавить");
		Utils.setFixedSize(add, 82, 22);
		add.addActionListener(Main.getEventListener());
		add.setActionCommand(eventPrefix + "-add");
		panel.add(add);
		
		JButton edit = new JButton("Редактировать");
		Utils.setFixedSize(edit, 120, 22);
		edit.setEnabled(false);
		edit.addActionListener(Main.getEventListener());
		edit.setActionCommand(eventPrefix + "-edit");
		panel.add(edit);
		
		JButton remove = new JButton("Удалить");
		Utils.setFixedSize(remove, 82, 22);
		remove.setEnabled(false);
		remove.addActionListener(Main.getEventListener());
		remove.setActionCommand(eventPrefix + "-remove");
		panel.add(remove);
		
		panel.add(Box.createHorizontalGlue());
		return panel;
	}
	
}
