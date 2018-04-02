package pat_kurs;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

public class VehicleFactory extends AbstractFactory {
	static APC[] apcs = new APC[] {
			new APC("Lazar BVT", "Serbia", "Yugoimport SDPR", null, 10, 8),
			new APC("Talha", "Pakistan", "Heavy Industries Taxila", null, 10, 8)
			};
	static Tank[] tanks = new Tank[] {
			new Tank("T-90", "Russia", "Uralvagonzavod", null, 2, 80),
			new Tank("Type 69", "China", "First Inner Mongolia Machinery Factory", null, 3, 70),
			new Tank("Leopard", "Germany", "Germany", null, 2, 90)
			};
	
	static private VehicleFactory singleton;
	ArrayList<aVehicle> flyweightarray = new ArrayList<aVehicle>();
	
	VehicleFactory() {
		flyweightarray.addAll(Arrays.asList(apcs));
		flyweightarray.addAll(Arrays.asList(tanks));
	}
	
	public ArrayList<aWeapon> WeaponList() {
		return (ArrayList<aWeapon>) flyweightarray.clone();
	}
	
	public static VehicleFactory getInstance() {
		if (singleton == null)
			singleton = new VehicleFactory();
		return singleton;
	}

	@Override
	iWeapon createWeapon(String weapon, String name, String country, String manu) {
		return null;
	}

	@Override
	iVehicle createVehicle(String vehicle, String name, String country, String manu) {
		Random r = new Random();
		for (aVehicle w : flyweightarray) {
			if (name.equals(w.name) && country.equals(w.country) && manu.equals(w.manufacturer))
				return (iVehicle) w;
		}
		switch (vehicle) {
		case "apc":
			return apcs[r.nextInt(apcs.length)];
		case "tank":
			return tanks[r.nextInt(tanks.length)];
		}
		return null;
	}
}
