package p2016;

import java.awt.geom.Point2D;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Random;

// человек
@SuppressWarnings("serial")
public class Person implements Serializable {
	private Point2D.Double position;	// позиция
	private int size;		// размер (кружка?)
	private int speed;		// скорость перемещения

	boolean hasCloth;		// есть куртка с собой
	boolean coatRoomCheck;	// сдавал куртку в гардероб
	boolean wantsToEat;		// хочет ли есть
	boolean wantsToDrink;	// хочет ли пить
	int toPrint;			// сколько листов нужно распечатать

	double wannaEatProb;	// вероятность, что захочет есть
	double wannaDrinkProb;	// вероятность, что захочет пить
	double wannaLeave;		// вероятность, что пойдет на выход

	public int cash;		// сколько имеет денег наличкой
	public int credit;		// сколько имеет денег на карте
	public WayPoint goingTo;// к какой точке сейчас идет
	public ArrayList<WayPoint> path;	// путь, по которому идет
	public ArrayList<String> log;	// события, произошедшие с человеком
	
	public WayPoint backToStore;	// назад от банкомата
	
	public boolean isSelected;				// выделен ли
	public boolean isWorker;				// работник ли
	public UsableMapObject object;			// объект работника
	
	Person(Point2D.Double p) {
		Random r = new Random();
		position = p;
		speed = r.nextInt(3) + 1;	// коэф. скорости 1...4
		size = r.nextInt(10) + 10;	// размер 10...20
		log = new ArrayList<String>();
		
		Logic.GeneratePersonInfo(this);
	}
	
	public Point2D.Double getPosition() {
		return position;
	}

	public void setPosition(Point2D.Double position) {
		this.position = position;
	}

	public int getSize() {
		return size;
	}
	public int getSpeed() {
		return speed;
	}
	public void setSize(int size) {
		this.size = size;
	}
	public void setSpeed(int speed) {
		this.speed = speed;
	}
}
