package cw.gui;

import java.awt.Component;
import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.Insets;
import java.awt.Window;
import java.awt.image.BufferedImage;
import java.text.SimpleDateFormat;
import java.util.Arrays;

import javax.imageio.ImageIO;

// Набор вспомогательных методов для работы с интерфейсом
public class Utils {
	
	private static SimpleDateFormat date = new SimpleDateFormat("dd.MM.yyyy");
	private static SimpleDateFormat time = new SimpleDateFormat("dd.MM HH:mm");
	
	public static void setFixedSize(Component c, int w, int h) {
		Dimension d = new Dimension(w, h);
		c.setPreferredSize(d);
		c.setMinimumSize(d);
		c.setMaximumSize(d);
	}
	
	public static void setFrameFavicon(Window frame, String path) {
		BufferedImage img = readImage(path);
		if(img != null) frame.setIconImage(img);
	}
	
	public static BufferedImage readImage(String path) {
		try {
			return ImageIO.read(Utils.class.getResource(path));
		} catch(Exception e) {
			e.printStackTrace();
			return null;
		}
	}
	
	public static GridBagConstraints getGridPosition(int x, int y, int w, int h, Insets i) {
		GridBagConstraints gbc = new GridBagConstraints();
		gbc.gridx = x;
		gbc.gridy = y;
		gbc.gridwidth = w;
		gbc.gridheight = h;
		gbc.insets = i;
		return gbc;
	}
	
	public static int[] addToIntArray(int[] a, int v) {
		int[] data = Arrays.copyOf(a, a.length + 1);
		data[a.length] = v;
		return data;
	}
	
	public static SimpleDateFormat getDateFormat(boolean t) {
		return t ? time : date;
	}
	
}
