package p2016;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.RenderingHints;
import java.awt.Stroke;
import java.io.Serializable;

import javax.swing.JPanel;

@SuppressWarnings("serial")
public class Panel extends JPanel implements Serializable {
	private static SimScreen currentSimScreen = null;					// какой экран имитации сейчас отрисовывается
	final static private Color wallColour = Color.BLACK;				// цвет стен
	final static private Color wayPointColour = Color.RED;				// цвет точек
	final static private Color UsableMapObjectColour = Color.DARK_GRAY;	// цвет точек
	final static int AIPointSize = 15;									// размер кружка у точек
	final static int UsableObjectWidth = 30;							// размер объектов
	final static int UsableObjectHeight = 30;

	@Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        doDrawing(g);
    }
	
	public static boolean checkRectToPointCollision(Rectangle rect, Point point) {
		if (rect.contains(point))
			return true;
		else
			return false;
	}
	
	public static boolean checkCircleToPointCollision(Point circle, int r, Point point) {
		int distance = (int) Math.sqrt(Math.pow((point.getX() - circle.getX()), 2) + Math.pow((point.getY() - circle.getY()), 2));
		if (distance < r)
			return true;
		else
			return false;
	}
	
	// отрисовка экрана
	private void doDrawing(Graphics g) {
		Graphics2D g2d = (Graphics2D) g;
		g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
	            RenderingHints.VALUE_ANTIALIAS_ON); 
		g2d.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING,
	            RenderingHints.VALUE_TEXT_ANTIALIAS_ON);
		g2d.setBackground(Color.white);
		if (currentSimScreen == null) return;
		// временная стена редактора
		if (currentSimScreen.tempWall != null) {
			Wall w = currentSimScreen.tempWall;
			g.setColor(Color.LIGHT_GRAY);
			g.fillPolygon(new int[]{w.getP().x,w.getP().x,w.getWallEnd().x,w.getWallEnd().x}, new int[]{w.getP().y,w.getWallEnd().y,w.getWallEnd().y,w.getP().y}, 4);
		}
		// временная линия точек редактора
		if (currentSimScreen.tempWayPointStart != null) {
			g2d.setColor(Color.CYAN);
			Stroke stroke = new BasicStroke(4f);
			g2d.setStroke(stroke);
			g2d.drawLine(currentSimScreen.tempWayPointStart.getP().x, 
					currentSimScreen.tempWayPointStart.getP().y, 
					currentSimScreen.tempWayPointEnd.x, 
					currentSimScreen.tempWayPointEnd.y);
		}
		// рисуем объекьы
		if (!currentSimScreen._objects.isEmpty()) {
			// стены
			for (MapObject wo : currentSimScreen._objects) {
				if (wo == null) continue;
				if (wo.getClass().getSimpleName().equals("Wall") ) {
					g.setColor(wallColour);
					Wall w = (Wall) wo;
					g.fillPolygon(new int[]{w.getP().x,w.getP().x,w.getWallEnd().x,w.getWallEnd().x}, new int[]{w.getP().y,w.getWallEnd().y,w.getWallEnd().y,w.getP().y}, 4);
				}
			}
			// используемые объекты
			for (MapObject wo : currentSimScreen._objects) {
				if (wo == null) continue;
				if ( wo.getClass().getSimpleName().equals("UsableMapObject") ) {
					UsableMapObject vm = (UsableMapObject) wo;
					
					g2d.setColor(Color.GREEN);
					Stroke stroke = new BasicStroke(4f);
					g2d.setStroke(stroke);
					if (vm.stayPoint != null && App.drawAI)
						g2d.drawLine(vm.getP().x, vm.getP().y, vm.stayPoint.getP().x, vm.stayPoint.getP().y);

					g.setColor(UsableMapObjectColour);
					g.fillRect(vm.getP().x - UsableObjectWidth/2, vm.getP().y - UsableObjectHeight/2, UsableObjectWidth, UsableObjectHeight);

					g.setColor(Color.LIGHT_GRAY);
					g.setFont(new Font("Arial", Font.BOLD, 12));
					String info = null;
					switch (vm.getType()) {
					case 0:
					case 4:
						info = vm.getHas() + "/" + vm.getCapacity();
						break;
					case 1:
						info = String.valueOf(vm.getHas());
						break;
					case 2:
					case 3:
						if (vm.admin != null)
							info = "Да";
						else
							info = "Нет";
						break;
					case 5:
						info = "";
						break;
					}
					g.drawString(info, vm.getP().x - g.getFontMetrics().stringWidth(info)/2, vm.getP().y - 12 + UsableObjectHeight/2);
					g.setColor(Color.green);
					g.setFont(new Font("Arial", Font.BOLD, 12));
					String text = null;
					switch (vm.getType()) {
					case 0:
						text = "Автомат (" + vm.getPrice() + ")";
						break;
					case 1:
						text = "Копицентр (" + vm.getPrice() + ")";
						break;
					case 2:
						text = "Гардероб";
						break;
					case 3:
						text = "Пост";
						break;
					case 4:
						text = "Магазин (" + vm.getPrice() + ")";
						break;
					case 5:
						text = "Банкомат";
						break;
					}
					g.drawString(text, vm.getP().x - g.getFontMetrics().stringWidth(text)/2, vm.getP().y - 20);
				}
			}
		}
		// рисуем точки и пути
		if (!currentSimScreen._waypoints.isEmpty() && App.drawAI)
			for (Object ob : currentSimScreen._waypoints) {
				WayPoint wo = (WayPoint) ob;
				if ( wo != null )
					if (wo.isSpawn)
						g.setColor(Color.CYAN);
					else
						g.setColor(wayPointColour);
				if (ob.getClass().getSimpleName().equals("UsableWayPoint")) {
					UsableWayPoint vm = (UsableWayPoint) ob;
					g.setColor(UsableMapObjectColour);
					g2d.setColor(UsableMapObjectColour);
					Stroke stroke = new BasicStroke(4f);
					g2d.setStroke(stroke);
					if (vm.object != null)
						g2d.drawLine(vm.getP().x, vm.getP().y, vm.object.getP().x, vm.object.getP().y);
				}
				g.fillArc(wo.getP().x - AIPointSize / 2, wo.getP().y - AIPointSize / 2, AIPointSize,
						AIPointSize, 0, 360);


				if (!wo._connected.isEmpty())
					for (WayPoint c : wo._connected)
						if (c != null) {
							g2d.setColor(wayPointColour);
							Stroke stroke = new BasicStroke(4f);
							g2d.setStroke(stroke);
							g2d.drawLine(c.getP().x, c.getP().y, wo.getP().x, wo.getP().y);
						}
					
			}
		// рисуем людей
		if (!currentSimScreen._persons.isEmpty())
			for (Person p : currentSimScreen._persons) {
				
				if (p.isSelected)
					g.setColor(Color.red);
				else
					g.setColor(Color.black);
				
				if (p.isWorker)
					g.setColor(Color.blue);
				
				g.fillOval( (int) p.getPosition().x - p.getSize()/2, (int) p.getPosition().y - p.getSize()/2, p.getSize(), p.getSize());
			}
		
		drawGUI(g);
	}

	private void drawGUI(Graphics g) {
		g.setColor(Color.MAGENTA);
		int w = App.winModeWidth;
		int h = App.winModeHeight;
		int min = Math.min(w, h);
		
		g.setFont(new Font("Arial", Font.BOLD, min / 30));

		int textHeight = min / 40;
		g.setFont(new Font("Arial", Font.PLAIN, textHeight));
		if (App.shiftHold) {
			String del = "Del - удалить объект";
			String add = "M1 - добавить объект ";
			String toAdd = null;
			switch (App.objectAdding) {
			case 0:
				toAdd = "[стена]";
				break;
			case 1:
				toAdd = "[точка перемещения]";
				break;
			case 2:
				toAdd = "[автомат с кофе]";
				break;
			case 3:
				toAdd = "[копицентр]";
				break;
			case 4:
				toAdd = "[гардероб]";
				break;
			case 5:
				toAdd = "[пост]";
				break;
			case 6:
				toAdd = "[магазин]";
				break;
			case 7:
				toAdd = "[банкомат]";
				break;
			}
			String d = "[  ] - переключение объектов";
			add += toAdd;
			g.drawString(del, 10, textHeight + 5);
			g.drawString(add, 10, (textHeight + 5)*2);
			g.drawString(d, 10, (textHeight + 5)*3);
			
			if (App.objectAdding == 1) {
				g.drawString("Зажать CTRL - удаление пути", 10, (textHeight + 5)*4);
				String pathDraw = "W - Отрисовка путей ";
				if (App.drawAI)
					pathDraw += "вкл.";
				else
					pathDraw += "выкл.";
				g.drawString(pathDraw, 10, (textHeight + 5)*5);
				g.drawString("Зажать ALT - точка для работника", 10, (textHeight + 5)*6);
			}
		} else {
			g.drawString("Shift - изменить", 10, textHeight + 5);
			g.drawString("Space - пауза", 10, (textHeight + 5)*2);
			g.drawString("Ctrl + L - загрузка", 10, (textHeight + 5)*3);
			g.drawString("Ctrl + S - сохранение", 10, (textHeight + 5)*4);
			g.drawString("Mouse 3 - информация о человеке", 10, (textHeight + 5)*5);
			if (App.peopleLimit == 0)
				g.drawString("Enter - запустить", 10, (textHeight + 5)*6);
		}
	}

	public static SimScreen getCurrentSimScreen() {
		return currentSimScreen;
	}

	public void setCurrentSimScreen(SimScreen currentSimScreen) {
		Panel.currentSimScreen = currentSimScreen;
	}
}
