package p2016;

import java.awt.Point;
import java.util.LinkedList;
import java.util.Queue;
import javax.swing.JOptionPane;
import javax.swing.Timer;

// используемый объект
@SuppressWarnings("serial")
public class UsableMapObject extends MapObject {
	private int capacity;					// вместимость
	private int has;						// сколько осталось
	private int type;						// тип объекта
	private int price;						// цена товара
	// 0 - автомат, 1 - печать, 2 - гардероб, 3 - пост, 4 - магазин, 5 - банкомат

	public int minTime = 1000, maxTime = 5000;	// нужное для обработки мин. и макс. время (в миллисекундах)
	public Queue<Person> queue;		// очередь
	public Person admin;			// кто относится к объекту
	public Timer timer;				// таймер для обработки очереди
	public WayPoint stayPoint;		// точка, где стоит работник
	
	public UsableMapObject(Point pos, int t) {
		super(pos);
		setType(t);
		queue = new LinkedList<Person>();
	}
	
	public boolean ChangeProperties() {
        String test1 = "0", test2 = "0", test3 = "0";
        switch (getType()) {
        case 0:
            test1 = JOptionPane.showInputDialog("Вместимость автомата (чашек кофе)");
            test2 = JOptionPane.showInputDialog("Сколько имеется чашек кофе в автомате");
            test3 = JOptionPane.showInputDialog("Цена кофе");
            break;
        case 1:
            test2 = JOptionPane.showInputDialog("Сколько имеется бумаги");
            test3 = JOptionPane.showInputDialog("Цена распечатки (за лист)");
            break;
        case 2:
        	break;
        case 3:
        	break;
        case 4:
            test1 = JOptionPane.showInputDialog("Вместимость магазина (кол-во еды)");
            test2 = JOptionPane.showInputDialog("Сколько имеется еды в магазине");
            test3 = JOptionPane.showInputDialog("Цена еды");
        	break;
        case 5:
            test1 = JOptionPane.showInputDialog("Вместимость банкомата (купюр)");
            test2 = JOptionPane.showInputDialog("Сколько имеется купюр в банкомате");
        	break;
        }
        int cap, h, p; 
        try {
        	cap = Integer.parseInt(test1);
        	h = Integer.parseInt(test2);
        	p = Integer.parseInt(test3);
        } catch (java.lang.NumberFormatException e) {
        	return false;
        }
        if ((h > cap && getType() != 1) || cap < 0 || h < 0 || p < 0)
        	return false;
        setCapacity(cap);
        setHas(h);
        setPrice(p);
        return true;
	}

	public int getPrice() {
		return price;
	}

	public void setPrice(int price) {
		this.price = price;
	}

	public int getType() {
		return type;
	}

	public void setType(int type) {
		this.type = type;
	}

	public int getCapacity() {
		return capacity;
	}

	public void setCapacity(int capacity) {
		this.capacity = capacity;
	}

	public int getHas() {
		return has;
	}

	public void setHas(int has) {
		this.has = has;
	}
}
