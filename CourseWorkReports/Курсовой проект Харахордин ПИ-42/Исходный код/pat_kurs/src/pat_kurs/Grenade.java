package pat_kurs;

public class Grenade extends aExplosive {
	int secsToExplode;
	Grenade(String n, String c, String m, String cal, int r, int sec) {
		super(n, c, m, cal, r);
		secsToExplode = sec;
	}
	@Override
	public void shoot() {
	}
	@Override
	public void load() {
	}
}
