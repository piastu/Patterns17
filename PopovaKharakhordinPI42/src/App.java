package p2016;

import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.MouseInfo;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.Toolkit;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.SwingUtilities;
import javax.swing.Timer;
import javax.swing.BoxLayout;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.ArrayList;
import java.util.Collections;
import java.util.ListIterator;
import java.util.Random;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.awt.geom.Point2D;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

@SuppressWarnings("serial")
public class App implements Serializable {
	JFrame frame;
	PersonInfo personInfo = null;		// окно с информацией о человеке
	static int winModeX, winModeY;      // x, y окна
	
	Panel panel;						// canvas
	ArrayList<SimScreen> _simscreens;	// все экраны имитации
	SimScreen mainScreen = null;		// главный экран имитации
	Timer redrawTimer;					// da
	Timer updateTimer;					// da
	final static int redrawDelay = 13;	// задержка между итерациями отрисовки
	final static int updateDelay = 26;	// задержка между итерациями обновления
	
	// TODO: запретить редактирование во время имитации
	public final static int winModeWidth = 1150, winModeHeight = 600; 	// ширина, высота окна
	public static boolean altHold, shiftHold, m1Hold, ctrlHold;
	public static boolean drawAI;
	public static boolean paused;
	public static int objectAdding = 0;	// какой оюъект добавляется
	public static int peopleLimit = 0;
	
	private static final String SAVE_FILE = "saved.dat";
	private static final int OBJECTS_NUM = 8;	// сколько всего объектов
	// 0 - стена
	// 1 - точка для перемещения
	// 2 - автомат с кофе
	// 3 - копицентр
	// 4 - гардероб
	// 5 - пост
	// 6 - магазин
	// 7 - банкомат
	
	public App() {
		initialize();
		
	    // параметры окна
	    Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
	    // выравниваем по центру
	    winModeX = (int) dim.getWidth()/2 - winModeWidth/2;
	    winModeY = (int) dim.getHeight()/2 - winModeHeight/2;
	    
		frame.setVisible(false);
		frame.dispose();
		frame.setUndecorated(true);
		frame.setResizable(false);
		frame.setBounds(winModeX, winModeY, winModeWidth, winModeHeight);
		frame.setVisible(true);
		frame.repaint();

	    redrawTimer = new Timer(redrawDelay, new ActionListener() {
	        public void actionPerformed(ActionEvent evt) {
	        	panel.repaint();
	        }
	    });
	    updateTimer = new Timer(updateDelay, new ActionListener() {
	        public void actionPerformed(ActionEvent evt) {
	        	// TODO: генерировать путь, если нет назначения и пути
	        	// брать следующую точку из пути, если сейчас в точке назн.
	        	// для обхода создать boolean[] размера _waypoints.size()
	        	
	        	// Collections.shuffle(Panel.getCurrentSimScreen()._waypoints);
	        	
	    		if ( !Panel.getCurrentSimScreen()._waypoints.isEmpty() && Panel.getCurrentSimScreen()._persons.size() < peopleLimit )
	    			// проход по все точкам респауна
	    			for (WayPoint point : Panel.getCurrentSimScreen()._waypoints) {
    					Random r2 = new Random();
    					double rd = r2.nextDouble();
	    				if (point.isSpawn && rd < 0.01) {
	    					Person p = new Person(new Point2D.Double(point.getP().x, point.getP().y));
	    					
	    					// если найден новый путь, добавить человека
	    					if (Logic.FindRandomPathToAnywhere(p, point, true))
		    				    Panel.getCurrentSimScreen()._persons.add(p);
	    				}
	    			}

	    		if (!Panel.getCurrentSimScreen()._persons.isEmpty())
	    			for (int i = 0; i < Panel.getCurrentSimScreen()._persons.size(); i++) {
		    			Person person = Panel.getCurrentSimScreen()._persons.get(i);
		    			Point2D.Double curPos = person.getPosition();

		    			double dx = person.goingTo.getP().x - curPos.x;
		    			double dy = person.goingTo.getP().y - curPos.y;	
		    			
		    			double curVectorLen = vectorLength(dx, dy);
		    			
		    			dx /= curVectorLen;
		    			dy /= curVectorLen;
		    			
		    			dx *= person.getSpeed();
		    			dy *= person.getSpeed();

		    			double newx = curPos.x + dx;
		    			double newy = curPos.y + dy;
		    			
		    			person.setPosition( new Point2D.Double( newx, newy ) );
		    			
		    			// обновление вероятностей
		    			person.wannaDrinkProb += Logic.gettingThursty;
		    			person.wannaEatProb += Logic.gettingHungry;
		    			Random r = new Random();
		    			
		    			if (!person.wantsToDrink && r.nextDouble() < person.wannaDrinkProb) {
		    				person.wantsToDrink = true;
		    				person.log.add(Logic.nowWannaDrink);
		    			}
		    			if (!person.wantsToEat && r.nextDouble() < person.wannaEatProb) {
		    				person.wantsToEat = true;
		    				person.log.add(Logic.nowWannaEat);
		    			}
		    			
		    			// дошел до точки пути
		    			if (Panel.checkCircleToPointCollision(person.goingTo.getP(), 5, new Point( (int) person.getPosition().x, (int) person.getPosition().y ) ) ) {

		    				// еще не дошел до конца
		    				if (person.path != null && !person.path.isEmpty()) {
			    				person.goingTo = person.path.get(0);
			    				person.path.remove(0);
		    				} else { 				
		    					// доешл до конца
		    					// если конечная - точка респауна, он уходит
		    					if (person.goingTo.isSpawn) {
				    				if (personInfo != null && personInfo.person == person)
				    					personInfo.log.setText(personInfo.log.getText() + "\n" + "ушел");
				    				Panel.getCurrentSimScreen()._persons.remove(person);
									continue;
		    					}
		    					// если работник - то идет на выход
				    			// работник
				    			if (person.isWorker) {
									person.path = null;
									if (person.object.getType() == 0 || person.object.getType() == 4)
										person.object.setHas(person.object.getCapacity());

									if (person.object.getType() == 1)
										person.object.setHas(200);
									
									person.log.add("пополнил");

									person.object.admin = null;
									if (Logic.FindRandomPathToExit(person, person.object.stayPoint))
										person.log.add(Logic.goingToExit);
				    			}
		    				}
		    			}
		    			// TODO: хватает ли товара
		    			// TODO: очереди
		    			// прошел весь путь (не работник)
		    			if (person.path != null && person.path.isEmpty() && !person.isWorker) {
		    				person.path = null;
		    				person.wannaLeave += Logic.wannaLeave;
		    				WayPoint wp = person.goingTo;
		    				
		    				// куда он пришел
							if (wp.getClass().getSimpleName().equals("UsableWayPoint")) {
								UsableWayPoint uwp = (UsableWayPoint) wp;
								
		    	    			// проверка, хватает ли денег
								int totalPrice = 0;
								int totalAmount = 0;
								switch (uwp.object.getType()) {
								case 0:
									totalPrice = uwp.object.getPrice();
									totalAmount = 1;
									break;
								case 4:
									totalPrice = uwp.object.getPrice();
									totalAmount = 2;
									break;
								case 1:
									totalPrice = uwp.object.getPrice()*person.toPrint;
									totalAmount = person.toPrint;
								}
								
								boolean notEnoughGood = false;
								// не хватает товара в автомате
								if (uwp.object.getHas() < totalAmount) 
									notEnoughGood = true;

								// денег не хватает, проверяем, есть ли на карте деньги
								if ( person.cash < totalPrice ) {
									if ( person.credit + person.cash >= totalPrice ) {
										// идем к банкомату
										Logic.FindRandomPathToUsable(person, wp, 5);
										person.backToStore = wp;
										person.log.add(Logic.noCash);
									} else {
										// денег нет, идет на выход
										// TODO: не на выход?
										person.log.add(Logic.noCredit);
										Logic.FindRandomPathToExit(person, wp);
									}
									continue;
								} else 
									person.cash -= totalPrice;
								
								if (!notEnoughGood)
									switch (uwp.object.getType()) {
									case 0:
										person.wannaDrinkProb = Logic.gettingThursty;
										person.wantsToDrink = false;
										uwp.object.setHas(uwp.object.getHas() - 1);
										person.log.add(Logic.drankSome);
										break;
									case 1:
										uwp.object.setHas(uwp.object.getHas() - person.toPrint);
										person.toPrint = 0;
										person.log.add(Logic.printed);
										break;
									case 2:
										if (person.coatRoomCheck) {
											person.hasCloth = true;
											person.coatRoomCheck = false;
											person.log.add(Logic.tookCloth);
										} else {
											person.hasCloth = false;
											person.coatRoomCheck = true;
											person.log.add(Logic.gaveCloth);
										}
										break;
									case 3:
										// TODO: пост?
										break;
									case 4:
										person.wannaEatProb = Logic.gettingHungry;
										person.wantsToEat = false;
										person.wannaDrinkProb = Logic.gettingThursty;
										person.wantsToDrink = false;
										uwp.object.setHas(uwp.object.getHas() - 2);
										person.log.add(Logic.ateSome + " и " + Logic.drankSome);
										break;
									case 5:
										// снимает все с карты
										person.cash += person.credit;
										person.credit = 0;
										person.log.add(Logic.goingBack);
										Logic.FindRandomPathToPoint(person, wp, person.backToStore);
										person.backToStore = null;
										break;
									}
								else {
									// товара не достаточно, идет на выход
									switch (uwp.object.getType()) {
								case 0:
									person.log.add(Logic.noDrinks);
									break;
								case 1:
									person.log.add(Logic.noPaper);
									break;
								case 4:
									person.log.add(Logic.noMeals);
									break;
									}
									Logic.FindRandomPathToExit(person, wp);
								}
								
								// ищем новую точку, если не возвращаемся от банкомата
								if (!notEnoughGood)
									if (uwp.object.getType() != 5)
										Logic.FindRandomPathToAnywhere(person, wp, false);
									} else {
										if (!wp.isSpawn) 
											Logic.FindRandomPathToAnywhere(person, wp, false);
									}
		    			}
	    			}
	    		if (personInfo != null && Panel.getCurrentSimScreen()._persons.contains(personInfo.person)) {
	    			Person p = personInfo.person;
					personInfo.cashField.setText(String.valueOf(p.cash));
					personInfo.checkCoatRoom.setSelected(p.coatRoomCheck);
					personInfo.creditField.setText(String.valueOf(p.credit));
					personInfo.hasCloth.setSelected(p.hasCloth);
					personInfo.wantsToDrink.setSelected(p.wantsToDrink);
					personInfo.wantsToEat.setSelected(p.wantsToEat);
					personInfo.printField.setText(String.valueOf(p.toPrint));
					personInfo.log.setText("");
					for (String s : p.log)
						personInfo.log.setText(personInfo.log.getText() + "\n" + s);
				}
	    		
	    		// отправить работников, если мало товара
	    		if (!Panel.getCurrentSimScreen()._objects.isEmpty() && Panel.getCurrentSimScreen()._persons.size() < peopleLimit)
	    			for (MapObject go : Panel.getCurrentSimScreen()._objects)
	    				if (go != null && go.getClass().getSimpleName().equals("UsableMapObject")) {
	    					UsableMapObject ugo = (UsableMapObject) go;
	    					Random r2 = new Random();
	    					// пополнение автомата и магазина
	    					if ( ((ugo.getHas() < ugo.getCapacity()*0.2 && (ugo.getType() == 0 || ugo.getType() == 4) && ugo.admin == null) ||
	    							(ugo.getHas() < Logic.minPaperLimit && ugo.getType() == 1 && ugo.admin == null)) && r2.nextDouble() < Logic.goingToTheWork ) {
		    					
	    						// находим точку респауна
	    						WayPoint spawnPoint = null;
	    		    			for (WayPoint point : Panel.getCurrentSimScreen()._waypoints)
	    		    				if (point != null && point.isSpawn) {
	    		    					spawnPoint = point;
	    		    					break;
	    		    				}
	    						Person worker = new Person(new Point2D.Double(spawnPoint.getP().x, spawnPoint.getP().y));
	    						worker.isWorker = true;
	    						ugo.admin = worker;
	    						worker.object = ugo;
	    						switch (ugo.getType()) {
	    						case 0:
	    							worker.log.add(Logic.refillVending);
	    							break;
	    						case 4:
	    							worker.log.add(Logic.refillStore);
	    							break;
	    						case 1:
	    							worker.log.add(Logic.refillCopy);
	    							break;
	    						}
	    						Panel.getCurrentSimScreen()._persons.add(worker);
		    					
		    					Logic.FindRandomPathToPoint(worker, spawnPoint, ugo.stayPoint);
	    					}
	    				}
	        }
	    });
	    
	    redrawTimer.start();
	    updateTimer.start();
	}
	
	// длина вектора
	private double vectorLength(double x, double y) {
		return Math.sqrt( x*x + y*y );
	}
	
	// обход в глубину до первого пути
	@SuppressWarnings("unchecked")
	static void dfs(WayPoint current, WayPoint end, boolean[] visited, ArrayList<WayPoint> path, Person person) {
		ArrayList<WayPoint> allWayPoints = Panel.getCurrentSimScreen()._waypoints;
		visited[ allWayPoints.indexOf( current ) ] = true;
		path.add(current);
		
		Collections.shuffle(current._connected);
		if (!current._connected.isEmpty())
			for (WayPoint toPoint : current._connected) {
				if (toPoint == end)
					if (person.path == null) {
						path.add(toPoint);
						path.remove(0);
						person.path = path;
					}
					else 
						;
				else if (visited[allWayPoints.indexOf(toPoint)] == false)
					if (person.path == null)
						dfs(toPoint, end, visited.clone(), (ArrayList<WayPoint>) path.clone(), person);
				
			}
	}

	private void initialize() {
		frame = new JFrame();
		frame.addMouseMotionListener(new MouseMotionAdapter() {
			@Override
			public void mouseDragged(MouseEvent arg0) {
				switch (arg0.getButton()) {
				case 0:
					if (shiftHold) 
						switch (objectAdding) {
						case 0:
							if (Panel.getCurrentSimScreen().tempWall != null)
								Panel.getCurrentSimScreen().tempWall.setWallEnd(arg0.getPoint());
							break;
						case 1:
							if (Panel.getCurrentSimScreen().tempWayPointStart != null)
								Panel.getCurrentSimScreen().tempWayPointEnd = arg0.getPoint();
							break;
						}
					break;
				}
			}
		});
		frame.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent arg0) {
				switch (arg0.getButton()) {
				case MouseEvent.BUTTON1:
					// рисуем объект
					if (shiftHold)
						switch (objectAdding) {
						case 0:
							Panel.getCurrentSimScreen().tempWall = new Wall(arg0.getPoint(), arg0.getPoint());
							break;
						case 1:
							if (Panel.getCurrentSimScreen()._waypoints != null) {
								// находим кликнутый кружок
								for (WayPoint wp : Panel.getCurrentSimScreen()._waypoints) {
									if (Panel.checkCircleToPointCollision(wp.getP(), Panel.AIPointSize, arg0.getPoint())) {
										// найден, создаем линию
										Panel.getCurrentSimScreen().tempWayPointStart = wp;
										Panel.getCurrentSimScreen().tempWayPointEnd = wp.getP();
										return;
									}
								}
							}
							// кружка нет, создаем
							boolean spawn = false;
							if (arg0.getPoint().x < 40 || arg0.getPoint().x > App.winModeWidth - 40 || arg0.getPoint().y < 40 || arg0.getPoint().y > App.winModeHeight - 40 )
								spawn = true;
							Panel.getCurrentSimScreen()._waypoints.add(new WayPoint(arg0.getPoint(), spawn));
							break;
						case 2:
						case 3:
						case 4:
						case 5:
						case 6:
						case 7:
					        UsableMapObject vm = new UsableMapObject(arg0.getPoint(), objectAdding - 2);
					        if (!vm.ChangeProperties())
					        	JOptionPane.showMessageDialog(null, "Введены неверные данные", "Ошибка", JOptionPane.ERROR_MESSAGE);
					        else
								Panel.getCurrentSimScreen()._objects.add(vm);
							break;
						}
					m1Hold = true;
					break;
				case MouseEvent.BUTTON2:
					// открываем окно и нфой о человеке
					for (Person p : Panel.getCurrentSimScreen()._persons)
						if (Panel.checkCircleToPointCollision(new Point( (int) p.getPosition().x, (int) p.getPosition().y ), p.getSize(), arg0.getPoint())) {
							if (personInfo == null)
								personInfo = new PersonInfo();
							else
								personInfo.person.isSelected = false;
							personInfo.person = p;
							p.isSelected = true;
							personInfo.cashField.setText(String.valueOf(p.cash));
							personInfo.checkCoatRoom.setSelected(p.coatRoomCheck);
							personInfo.creditField.setText(String.valueOf(p.credit));
							personInfo.hasCloth.setSelected(p.hasCloth);
							personInfo.wantsToDrink.setSelected(p.wantsToDrink);
							personInfo.wantsToEat.setSelected(p.wantsToEat);
							personInfo.printField.setText(String.valueOf(p.toPrint));
							personInfo.log.setText("");
							for (String s : p.log)
								personInfo.log.setText(personInfo.log.getText() + "\n" + s);
							personInfo.frame.setVisible(true);
							break;
						}
					break;
				}
			}
			@Override
			public void mouseReleased(MouseEvent arg0) {
				switch (arg0.getButton()) {
				case MouseEvent.BUTTON1:
					m1Hold = false;
					// сохраняем стену, если рисовали
					if (shiftHold) {
						switch (objectAdding) {
						case 0:
							Panel.getCurrentSimScreen().addObject(Panel.getCurrentSimScreen().tempWall);
							Panel.getCurrentSimScreen().tempWall = null;
							break;
						case 1:
							if (Panel.getCurrentSimScreen().tempWayPointStart != null) {
								if (!Panel.getCurrentSimScreen()._objects.isEmpty() && shiftHold) {
									ListIterator<MapObject> it = Panel.getCurrentSimScreen()._objects.listIterator();    
							        while (it.hasNext()) {  
							        	Point cursor = MouseInfo.getPointerInfo().getLocation();
							        	SwingUtilities.convertPointFromScreen(cursor, frame);
							        	MapObject mo = it.next();
							        	if (mo == null) continue;
										if ( mo.getClass().getSimpleName().equals("UsableMapObject")) {
											UsableMapObject vm = (UsableMapObject) mo;
											// проверяем, пересекается ли
											Rectangle rect = new Rectangle(new Point(vm.getP().x - Panel.UsableObjectWidth/2, vm.getP().y - Panel.UsableObjectHeight/2));
											rect.add(new Point(vm.getP().x + Panel.UsableObjectWidth/2,vm.getP().y + Panel.UsableObjectHeight/2));
											
											if (Panel.checkRectToPointCollision(
													rect, 
													cursor)) {
												if (altHold) {
													// добавляем точку к объекту
													vm.stayPoint = Panel.getCurrentSimScreen().tempWayPointStart;
													continue;
												}
												
												// заменяем точку на точку с объектом
												UsableWayPoint newvm = new UsableWayPoint(Panel.getCurrentSimScreen().tempWayPointStart.getP());
												newvm._connected = Panel.getCurrentSimScreen().tempWayPointStart._connected;
												newvm.object = vm;
												Panel.getCurrentSimScreen()._waypoints.remove(Panel.getCurrentSimScreen().tempWayPointStart);
												Panel.getCurrentSimScreen()._waypoints.add(newvm);
												
												if (!newvm._connected.isEmpty())
													for (WayPoint c : newvm._connected)
														if (c != null) {
															c._connected.remove(Panel.getCurrentSimScreen().tempWayPointStart);
															c._connected.add(newvm);
														}
											}
										}
							        }
								}
								
								if (Panel.getCurrentSimScreen()._waypoints != null)
									// находим вторую точку под курсором
									for (WayPoint wp : Panel.getCurrentSimScreen()._waypoints) {
										if (Panel.checkCircleToPointCollision(wp.getP(), Panel.AIPointSize, arg0.getPoint())) {
											// вторая точка найдена, соединяем их или разъединяем
											if (!ctrlHold && Panel.getCurrentSimScreen().tempWayPointStart != wp) {
												if (!wp._connected.contains(Panel.getCurrentSimScreen().tempWayPointStart))
													wp._connected.add(Panel.getCurrentSimScreen().tempWayPointStart);
												if (!Panel.getCurrentSimScreen().tempWayPointStart._connected.contains(wp))
													Panel.getCurrentSimScreen().tempWayPointStart._connected.add(wp);
											} else {
												wp._connected.remove(Panel.getCurrentSimScreen().tempWayPointStart);
												Panel.getCurrentSimScreen().tempWayPointStart._connected.remove(wp);
											}
											break;
										}
									}
								Panel.getCurrentSimScreen().tempWayPointStart = null;
								Panel.getCurrentSimScreen().tempWayPointEnd = null;
							}
							break;
						}
					}
					break;
				}
			}
		});
		frame.addKeyListener(new KeyAdapter() {
			@Override
			public void keyPressed(KeyEvent arg0) {
				switch (arg0.getKeyCode()) {
				// зажимаем альт
				case KeyEvent.VK_ALT:
					altHold = true;
					break;
				case KeyEvent.VK_CONTROL:
					ctrlHold = true;
					break;
				case KeyEvent.VK_SHIFT:
					shiftHold = true;
					break;
				case KeyEvent.VK_ENTER:
					peopleLimit = 25;
					break;
				// пауза
				case KeyEvent.VK_SPACE:
					if (!paused) {
						updateTimer.stop();
						redrawTimer.stop();
						paused = true;
					} else {
						updateTimer.start();
						redrawTimer.start();
						paused = false;
					}
					break;
				// удаляем объект, если на нем курсор
				case KeyEvent.VK_DELETE:
					if (!Panel.getCurrentSimScreen()._objects.isEmpty() && shiftHold) {
						ListIterator<MapObject> it = Panel.getCurrentSimScreen()._objects.listIterator();    
				        while (it.hasNext()) {  
				        	Point cursor = MouseInfo.getPointerInfo().getLocation();
				        	SwingUtilities.convertPointFromScreen(cursor, frame);
				        	MapObject mo = it.next();
				        	if (mo == null) continue;
							if ( mo.getClass().getSimpleName().equals("Wall")) {
								Wall w = (Wall) mo;
								// проверяем, пересекается ли
								Rectangle rect= new Rectangle(w.getP());
								rect.add(w.getWallEnd());
								
								if (Panel.checkRectToPointCollision(
										rect, 
										cursor))
									it.remove();
							}
							if ( mo.getClass().getSimpleName().equals("UsableMapObject")) {
								UsableMapObject vm = (UsableMapObject) mo;
								// проверяем, пересекается ли
								Rectangle rect = new Rectangle(new Point(vm.getP().x - Panel.UsableObjectWidth/2, vm.getP().y - Panel.UsableObjectHeight/2));
								rect.add(new Point(vm.getP().x + Panel.UsableObjectWidth/2, vm.getP().y + Panel.UsableObjectHeight/2));
								
								if (Panel.checkRectToPointCollision(
										rect, 
										cursor)) {
									if (!Panel.getCurrentSimScreen()._waypoints.isEmpty()) 
										for (WayPoint wp : Panel.getCurrentSimScreen()._waypoints)
											if (wp.getClass().getSimpleName().equals("UsableWayPoint")) {
												UsableWayPoint vwp = (UsableWayPoint) wp;
												if (vwp.object == vm) {
													Panel.getCurrentSimScreen()._waypoints.remove(vwp);
													break;
												}
											}
									
									it.remove();
									
								}
							}
				        }
					}
					if (!Panel.getCurrentSimScreen()._waypoints.isEmpty() && shiftHold && drawAI) {
						ListIterator<WayPoint> it = Panel.getCurrentSimScreen()._waypoints.listIterator();    
				        while (it.hasNext()) {  
				        	Point cursor = MouseInfo.getPointerInfo().getLocation();
				        	SwingUtilities.convertPointFromScreen(cursor, frame);
				        	WayPoint mo = it.next();
							if ( mo != null ) {
								// проверяем, пересекается ли
								if (Panel.checkCircleToPointCollision(mo.getP(), Panel.AIPointSize, cursor)) {
									// удаляем точку
									it.remove();
									// удаляем связи со смежными точками
									if (!mo._connected.isEmpty())
										for (WayPoint cwp : mo._connected)
											cwp._connected.remove(mo);
								}
							}
				        }
					}
					break;
				case KeyEvent.VK_S:
					if (ctrlHold) {
				         try {
							FileOutputStream fileOut =
							         new FileOutputStream(SAVE_FILE);
					        ObjectOutputStream out = new ObjectOutputStream(fileOut);
					        
					        if (!_simscreens.isEmpty())
					        	for (SimScreen ss : _simscreens) {
					        		if (!ss._objects.isEmpty())
								        out.writeObject(ss);
					        	}
					        
					        out.close();
						} catch (IOException e) {
				        	JOptionPane.showMessageDialog(null, "Ошибка записи в файл " + SAVE_FILE, "Ошибка", JOptionPane.ERROR_MESSAGE);
						}
					}
					break;
				case KeyEvent.VK_L:
					if (ctrlHold) {
				         FileInputStream fileIn = null;
						try {
							fileIn = new FileInputStream(SAVE_FILE);
						} catch (FileNotFoundException e1) {
				        	JOptionPane.showMessageDialog(null, "Ошибка загрузки из файла " + SAVE_FILE, "Ошибка", JOptionPane.ERROR_MESSAGE);
						}
				         ObjectInputStream in = null;
						try {
							in = new ObjectInputStream(fileIn);
							_simscreens.clear();
					         while (true) {
					        	Object o = in.readObject();
						        if (o.getClass().getSimpleName().equals("SimScreen")) {
						        	SimScreen sm = (SimScreen) o;
						        	if (sm.isMain)
						        		mainScreen = sm;
						        	_simscreens.add(sm);
						        	panel.setCurrentSimScreen(sm);
						        }
					         }
						} catch (java.io.EOFException e) {
							// объекты в файле закончились
						} catch (IOException e) {
				        	JOptionPane.showMessageDialog(null, "Ошибка при десериализации", "Ошибка", JOptionPane.ERROR_MESSAGE);
						} catch (ClassNotFoundException e) {
				        	JOptionPane.showMessageDialog(null, "Неизвестный класс", "Ошибка", JOptionPane.ERROR_MESSAGE);
							e.printStackTrace();
						}
				        try {
							in.close();
					        fileIn.close();
						} catch (IOException e) {
				        	JOptionPane.showMessageDialog(null, "Ошибка закрытия потоков при десериализации", "Ошибка", JOptionPane.ERROR_MESSAGE);
						}
					}
					break;
				case KeyEvent.VK_OPEN_BRACKET:
					if (shiftHold) {
						objectAdding--;
						if (objectAdding == -1)
							objectAdding = OBJECTS_NUM-1;
					}
					break;
				case KeyEvent.VK_CLOSE_BRACKET:
					if (shiftHold) {
						objectAdding++;
						if (objectAdding == OBJECTS_NUM)
							objectAdding = 0;
					}
					break;
				case KeyEvent.VK_W:
					if (shiftHold)
						drawAI = !drawAI;
					break;
				}
			}
			public void keyReleased(KeyEvent arg0) {
				// альт отжат
				switch (arg0.getKeyCode()) {
				// зажимаем альт
				case KeyEvent.VK_ALT:
					altHold = false;
					break;
				case KeyEvent.VK_CONTROL:
					ctrlHold = false;
					break;
				case KeyEvent.VK_SHIFT:
					shiftHold = false;
					Panel.getCurrentSimScreen().tempWall = null;
					Panel.getCurrentSimScreen().tempWayPointStart = null;
					Panel.getCurrentSimScreen().tempWayPointEnd = null;
					break;
				}
			}
		});
		frame.setBounds(100, 100, 689, 467);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(new BoxLayout(frame.getContentPane(), BoxLayout.X_AXIS));
		
		panel = new Panel();
		panel.setDoubleBuffered(true);
		frame.getContentPane().add(panel);
		
		// создаем пустой главный экран
	    _simscreens = new ArrayList<SimScreen>();
		SimScreen emptyScreen = new SimScreen(true);
		mainScreen = emptyScreen;
	    _simscreens.add(emptyScreen);
		panel.setCurrentSimScreen(emptyScreen);
	}
	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					App window = new App();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
}
