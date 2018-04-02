package pat_kurs;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {
	
	private static Stage mainStage = null;
	
	public static Stage getStage() {
		return mainStage;
	}

	@Override
	public void start(Stage stage) throws Exception {
		Parent root = FXMLLoader.load(getClass().getResource("Main.fxml"));

		AbstractFactory f = new FactoryProducer().getFactory("weapon");
		AbstractFactory h = new FactoryProducer().getFactory("vehicle");
		ArrayList<aWeapon> weaponList = new ArrayList<aWeapon>();
		weaponList.addAll(f.WeaponList());
		weaponList.addAll(h.WeaponList());
		String line;
		FileInputStream fin = null;
		BufferedReader br = null;
		InputStreamReader isr = null;
		try {
			fin = new FileInputStream("res/amps.txt");
			isr = new InputStreamReader(fin);
			br = new BufferedReader(isr);
			while ((line = br.readLine()) != null) {
				if (line.isEmpty())
					continue;
				String[] ss = line.split(";");
				for (aWeapon wep : weaponList) {
					if (wep.name.compareToIgnoreCase(ss[0]) == 0) {
						wep.ampl = Integer.valueOf(ss[1]);
					}
				}
			}
		} finally {
			if (br != null)
				br.close();
			if (isr != null)
				isr.close();
			if (fin != null)
				fin.close();
		}
			       
		mainStage = stage;
		Scene scene = new Scene(root);   
		stage.setTitle("Распознание оружия по звуку");
		stage.setScene(scene);
		stage.show();
	}
    
    public static void main(String[] args) {
        Application.launch(args);
    }
}
