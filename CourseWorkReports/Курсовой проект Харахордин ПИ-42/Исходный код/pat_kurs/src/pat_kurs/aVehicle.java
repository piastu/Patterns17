package pat_kurs;

import java.util.ArrayList;

import javafx.scene.media.AudioClip;

public abstract class aVehicle extends aWeapon implements iVehicle, iContainer {
	int seats;
	public ArrayList<aFirearm> guns;
	AudioClip driveSound;

	aVehicle(String n, String c, String m, String cal, int s) {
		super(n, c, m, cal);
		seats = s;
		guns = new ArrayList<aFirearm>();
	}
	
   @Override
   public iIterator getIterator() {
      return new FirearmIterator();
   }
	
	public class FirearmIterator implements iIterator {
		int index = 0;

		@Override
		public boolean hasNext() {
			if (index < guns.size())
				return true;
			else
				return false;
		}

		@Override
		public aFirearm next() {
			if (this.hasNext())
				return guns.get(index++);
			return null;
		}
	}
}
