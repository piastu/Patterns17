package pat_kurs;

public class Tank extends aVehicle {
	int tracksDepth;
	
	Tank(String n, String c, String m, String cal, int s, int d) {
		super(n, c, m, cal, s);
		tracksDepth = d;
	}

	@Override
	public void shoot(int num) {}

	@Override
	public void drive() {}
}
