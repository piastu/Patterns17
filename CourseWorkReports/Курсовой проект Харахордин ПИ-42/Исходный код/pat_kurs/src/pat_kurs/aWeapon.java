package pat_kurs;

import javafx.scene.media.AudioClip;

public abstract class aWeapon {
	String name, country, manufacturer, caliber;
	AudioClip shootSound, loadSound;
	public int ampl;
	
	aWeapon(String n, String c, String m, String cal) {
		name = n;
		country = c;
		manufacturer = m;
		caliber = cal;
	}
}
