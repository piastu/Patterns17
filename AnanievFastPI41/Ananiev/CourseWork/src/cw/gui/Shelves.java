package cw.gui;

import java.awt.Color;
import java.awt.Cursor;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JPanel;

import cw.Main;
import cw.model.AbstractMeans;

// Класс "полок" для хранения методов решения
@SuppressWarnings("serial")
public class Shelves extends JPanel {
	
	private final int width = 631, height = 71;
	
	public Shelves() {
		Utils.setFixedSize(this, width, height);
		
		this.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
		this.addMouseListener(new MouseAdapter(){
			public void mouseReleased(MouseEvent e) {
				Main.getEventListener().onCanvasClick(e.getY() / 35, e.getX() / 35);
			}
		});
	}
	
	@Override
	public void paintComponent(Graphics g) {
		g.setColor(Color.WHITE);
		g.fillRect(0, 0, width, height);
		g.setColor(new Color(0xDCDCDC));
		g.drawRect(0, 0, width - 1, height - 1);
		
		g.drawLine(0, 35, width - 1, 35);
		for(int i = 0; i < 17; i++) g.drawLine((i + 1) * 35, 0, (i + 1) * 35, height - 1);
		
		AbstractMeans[][] m = Main.getMeans();
		for(int i = 0; i < m.length; i++)
			for(int j = 0; j < m[i].length; j++)
				if(m[i][j] != null) paintElementAt(g, i, j, m[i][j]);
	}
	
	private void paintElementAt(Graphics g, int x, int y, AbstractMeans m) {
		g.setColor(new Color(m.isSelected() ? 0xb3eca4 : 0xf0f6fd));
		g.fillRect(y * 35 + 1, x * 35 + 1, 34, 34);
		
		Image img = Utils.readImage(m.getIconLocation());
		if(img != null) g.drawImage(img, y * 35 + 2, x * 35 + 2, null);
	}
	
	private void paintEmptySlot(Graphics g, int x, int y) {
		g.setColor(Color.WHITE);
		g.fillRect(y * 35 + 1, x * 35 + 1, 34, 34);
	}
	
	public void reloadSlot(int x, int y) {
		AbstractMeans[][] m = Main.getMeans();
		if(m[x][y] == null) paintEmptySlot(this.getGraphics(), x, y); else paintElementAt(this.getGraphics(), x, y, m[x][y]);
	}
	
}
