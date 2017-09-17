package cw;

import java.io.File;
import java.util.ArrayList;

import javax.swing.UIManager;

import cw.gui.MainFrame;
import cw.model.AbstractMeans;

// Основной класс, содержит точку входа и основные объекты программы
public class Main {
	
	private static MainFrame mainFrame;
	private static EventListener listener;
	
	private static FileIO fileIO;
	private static File file = null;
	
	private static AbstractMeans[][] means = new AbstractMeans[2][18];
	
	public static void main(String[] args) throws Exception {
		UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		
		listener = new EventListener();
		fileIO = new FileIO();
		
		mainFrame = new MainFrame();
		mainFrame.setVisible(true);
	}
	
	public static MainFrame getMainFrame() {
		return mainFrame;
	}
	
	public static EventListener getEventListener() {
		return listener;
	}
	
	public static FileIO getFileIO() {
		return fileIO;
	}
	
	public static File getFile() {
		return file;
	}
	
	public static void setFile(File f) {
		file = f;
	}
	
	public static AbstractMeans[][] getMeans() {
		return means;
	}
	
	public static ArrayList<AbstractMeans> getMeansAsList() {
		return getList(AbstractMeans.class);
	}
	
	@SuppressWarnings("unchecked")
	public static <T extends AbstractMeans> ArrayList<T> getList(Class<T> c) {
		ArrayList<T> list = new ArrayList<T>();
		for(int i = 0; i < means.length; i++)
			for(int j = 0; j < means[i].length; j++)
				if(means[i][j] != null && c.isInstance(means[i][j])) list.add((T)means[i][j]);
		return list;
	}
	
	public static void cleatMeans() {
		means = new AbstractMeans[2][18];
	}
	
	public static void loadMeans(ArrayList<? extends AbstractMeans> a) {
		for(AbstractMeans m : a) means[m.getX()][m.getY()] = m;
	}
	
}
