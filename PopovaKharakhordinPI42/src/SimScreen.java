package p2016;

import java.awt.Point;
import java.io.Serializable;
import java.util.ArrayList;

// экран имитации
public class SimScreen implements Serializable {
	private static final long serialVersionUID = 7011961340497995084L;
	ArrayList<Person> _persons;		// все люди на этом экране
	ArrayList<MapObject> _objects;	// все объекты на этом экране
	ArrayList<WayPoint> _waypoints;	// точки, по которым будутх одить люди
	SimScreen[] _neighbours;		// 4 соседних экраны 
	
	public Wall tempWall;				// временная стена для редактора
	public WayPoint tempWayPointStart;	
	public Point tempWayPointEnd;		
	
	boolean isMain;					// главный ли экран
	// 0 - UP, 1 - RIGHT, 2 - BOTTOM, 3 - LEFT
	
	SimScreen(boolean main) {
		isMain = main;
		_persons = new ArrayList<Person>();
		_objects = new ArrayList<MapObject>();
		_waypoints = new ArrayList<WayPoint>();
		_neighbours = new SimScreen[4];
	}
	
	public void addObject(MapObject mo) {
		_objects.add(mo);
	}
}
