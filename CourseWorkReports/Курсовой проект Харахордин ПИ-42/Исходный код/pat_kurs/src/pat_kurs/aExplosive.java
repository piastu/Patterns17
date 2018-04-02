package pat_kurs;

public abstract class aExplosive extends aWeapon implements iWeapon {
	int radius;
	
	aExplosive(String n, String c, String m, String cal, int r) {
		super(n, c, m, cal);
		radius = r;
	}
}
