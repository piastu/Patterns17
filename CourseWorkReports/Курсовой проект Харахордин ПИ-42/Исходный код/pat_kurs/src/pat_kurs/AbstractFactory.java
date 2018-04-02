package pat_kurs;

import java.util.ArrayList;

public abstract class AbstractFactory {
	abstract iWeapon createWeapon(String weapon, String name, String country, String manu);
	abstract iVehicle createVehicle(String vehicle, String name, String country, String manu);
	abstract ArrayList<aWeapon> WeaponList();
}
