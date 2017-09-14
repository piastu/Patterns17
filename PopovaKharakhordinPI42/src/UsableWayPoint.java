package p2016;

import java.awt.Point;
import java.io.Serializable;

//waypoint
@SuppressWarnings("serial")
public class UsableWayPoint extends WayPoint implements Serializable {

	UsableMapObject object;		// объект, с которым связана точка
	
	public UsableWayPoint(Point p0) {
		super(p0, false);
	}

	public UsableMapObject getObject() {
		return object;
	}

	public void setObject(UsableMapObject object) {
		this.object = object;
	}
	
}
