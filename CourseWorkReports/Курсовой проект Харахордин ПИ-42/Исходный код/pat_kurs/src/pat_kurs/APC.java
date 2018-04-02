package pat_kurs;

public class APC extends aVehicle {
	int wheels;

	APC(String n, String c, String m, String cal, int s, int w) {
		super(n, c, m, cal, s);
		wheels = w;
	}

	@Override
	public void shoot(int num) {}

	@Override
	public void drive() {}
}
