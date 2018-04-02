package pat_kurs;

public class FactoryProducer {
	public static AbstractFactory getFactory(String choice) {
		if (choice.equalsIgnoreCase("weapon")) {
			return WeaponFactory.getInstance();

		} else if (choice.equalsIgnoreCase("vehicle")) {
			return VehicleFactory.getInstance();
		}

		return null;
	}
}