package pat_kurs;

public class AssaultRifle extends aFirearm {
	int barrels;
	
	AssaultRifle(String n, String c, String m, String cal, int b) {
		super(n, c, m, cal);
		barrels = b;
	}

	@Override
	public void shoot() {
	}

	@Override
	public void load() {
	}
}
