package cw;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JFileChooser;
import javax.swing.filechooser.FileFilter;

import cw.model.Disease;
import cw.model.Herbal;
import cw.model.Patient;
import cw.model.Tincture;

// Класс для работы с диалогами открытия/сохранения файла и файловой системой
public class FileIO {
	
	private final JFileChooser chooser;
	
	public FileIO() {
		chooser = new JFileChooser();
		chooser.setAcceptAllFileFilterUsed(false);
		chooser.addChoosableFileFilter(new FileFilter() {
			@Override
			public boolean accept(File f) {
				if(f.isDirectory()) return true;
				return f.getName().endsWith(".dat");
			}

			@Override
			public String getDescription() {
				return "Data files (*.dat)";
			}
		});
	}
	
	public File getSaveFile() {
		if(chooser.showSaveDialog(Main.getMainFrame()) == JFileChooser.APPROVE_OPTION) {
			File f = chooser.getSelectedFile();
			if(f.getName().endsWith(".dat")) return f; else return new File(f.getAbsolutePath() + ".dat");
		}
		return null;
	}
	
	public File getOpenFile() {
		if(chooser.showOpenDialog(Main.getMainFrame()) == JFileChooser.APPROVE_OPTION) return chooser.getSelectedFile();
		return null;
	}
	
	public void saveToFile(File f) {
		try {
			OutputStream stream = new FileOutputStream(f);
			DataOutputStream out = new DataOutputStream(stream);
			
			writeListToFile(Main.getMainFrame().getDiseasesAsList(), out);
			writeListToFile(Main.getMainFrame().getPatientsAsList(), out);
			
			writeListToFile(Main.getList(Herbal.class), out);
			writeListToFile(Main.getList(Tincture.class), out);
			
			stream.close();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	private void writeListToFile(List<? extends ISaveable> list, DataOutputStream out) throws Exception {
		out.writeInt(list.size());
		for(ISaveable s : list) s.writeToFile(out);
	}
	
	public boolean readFromFile(File f) {
		try {
			InputStream stream = new FileInputStream(f);
			DataInputStream in = new DataInputStream(stream);
			
			ArrayList<Disease> diseases = readListFromFile(Disease.class, in);
			ArrayList<Patient> patients = readListFromFile(Patient.class, in);
			
			ArrayList<Herbal> herbals = readListFromFile(Herbal.class, in);
			ArrayList<Tincture> tinctures = readListFromFile(Tincture.class, in);
			
			stream.close();
			
			Main.getMainFrame().loadDiseases(diseases);
			Main.getMainFrame().loadPatients(patients);
			
			Main.cleatMeans();
			Main.loadMeans(herbals);
			Main.loadMeans(tinctures);
			Main.getMainFrame().getShelves().repaint();
			
			return true;
		} catch(Exception e) {
			return false;
		}
	}
	
	private <T extends ISaveable> ArrayList<T> readListFromFile(Class<T> c, DataInputStream in) throws Exception {
		int size = in.readInt();
		ArrayList<T> list = new ArrayList<T>();
		
		for(int i = 0; i < size; i++) {
			T obj = c.newInstance();
			obj.readFromFile(in);
			list.add(obj);
		}
		return list;
	}
	
}
