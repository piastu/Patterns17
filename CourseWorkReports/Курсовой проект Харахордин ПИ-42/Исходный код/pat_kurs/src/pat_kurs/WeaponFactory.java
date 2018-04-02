package pat_kurs;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

public class WeaponFactory extends AbstractFactory {
	static Grenade[] grenades = new Grenade[] {
			new Grenade("M67", "US", "US", "composition B", 500, 4),
			new Grenade("F1", "Russia", "Russia", "60-gram explosive charge", 300, 6),
			new Grenade("Breda Mod. 35", "Italy", "Breda Meccanica Bresciana", "Trinitrotoluene", 450, 5)
			};
	static AssaultRifle[] ars = new AssaultRifle[] {
			new AssaultRifle("AK-47", "Soviet Union", "Kalashnikov Concern", "7.62", 1),
			new AssaultRifle("M4A1", "US", "Colt's Manufacturing Company", "5.56", 1),
			new AssaultRifle("HK433", "Germany", "Heckler & Koch", "5.56", 1)
			};
	
	static private WeaponFactory singleton;
	ArrayList<aWeapon> flyweightarray = new ArrayList<aWeapon>();
	
	WeaponFactory() {
		flyweightarray.addAll(Arrays.asList(ars));
		flyweightarray.addAll(Arrays.asList(grenades));
	}
	
	public static WeaponFactory getInstance() {
		if (singleton == null)
			singleton = new WeaponFactory();
		return singleton;
	}
	
	public ArrayList<aWeapon> WeaponList() {
		return (ArrayList<aWeapon>) flyweightarray.clone();
	}

	@Override
	iWeapon createWeapon(String weapon, String name, String country, String manu) {
		Random r = new Random();
		for (aWeapon w : flyweightarray) {
			if (name.equals(w.name) && country.equals(w.country) && manu.equals(w.manufacturer))
				return (iWeapon) w;
		}
		switch (weapon) {
		case "grenade":
			return grenades[r.nextInt(grenades.length)];
		case "ar":
			return ars[r.nextInt(ars.length)];
		}
		return null;
	}

	@Override
	iVehicle createVehicle(String vehicle, String name, String country, String manu) {
		return null;
	}
}
