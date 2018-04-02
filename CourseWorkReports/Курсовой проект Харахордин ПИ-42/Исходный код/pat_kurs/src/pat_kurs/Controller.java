package pat_kurs;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.stage.FileChooser;

public class Controller 
{
	@FXML private TextField filePath;
	@FXML private Button proc;
	@FXML private Button openFileDialog;
	@FXML private Button sound1;
	@FXML private Button sound2;
	@FXML private Label type;
	@FXML private Label name;
	@FXML private Label country;
	@FXML private Label fact;
	@FXML private Label cal;
	
	public void chooseFile() {
		FileChooser fileChooser = new FileChooser();
		fileChooser.setInitialDirectory(new File("C:\\Users\\westy\\Documents\\workspace\\pat_kurs\\res"));
		fileChooser.setTitle("Open Resource File");
		File file = fileChooser.showOpenDialog(Main.getStage());
		if (file != null)
			filePath.setText(file.getAbsolutePath());
	}
	
	public void doProc() throws IOException {
		aWeapon wep = ProcessAudio.ProcessAudio(filePath.getText());
		if (wep == null)
			return;
		switch (wep.getClass().getSimpleName()) {
		case "Grenade":
			type.setText("�������");

			sound1.setText("�����");
			sound2.setText("Cooking");
			break;
		case "AssaultRifle":
			type.setText("��������� ��������");

			sound1.setText("��������");
			sound2.setText("�����������");
			break;
		case "APC":
			type.setText("���������������");

			sound1.setText("��������");
			sound2.setText("����");
			break;
		case "Tank":
			type.setText("����");

			sound1.setText("��������");
			sound2.setText("����");
			break;
		}
		name.setText(wep.name);
		fact.setText(wep.manufacturer);
		country.setText(wep.country);
		cal.setText(wep.caliber);
		/*Random r = new Random();
		aWeapon a;
		boolean b = r.nextBoolean();
		switch (r.nextInt(1)) {
		case 0:
			AbstractFactory f = new FactoryProducer().getFactory("weapon");
			iWeapon w = ((WeaponFactory) f).createWeapon(b ? "ar" : "grenade", "", "", "");
			if (b) {
				AssaultRifle ar = (AssaultRifle) w;
				type.setText("��������� ��������");
				name.setText(ar.name);
				fact.setText(ar.manufacturer);
				country.setText(ar.country);
				cal.setText(ar.caliber);

				sound1.setText("��������");
				sound2.setText("�����������");
			} else {
				Grenade ar = (Grenade) w;
				type.setText("�������");
				name.setText(ar.name);
				fact.setText(ar.manufacturer);
				country.setText(ar.country);
				cal.setText(ar.caliber);

				sound1.setText("�����");
				sound2.setText("Cooking");
			}
			break;
		case 1:
			AbstractFactory h = new FactoryProducer().getFactory("vehicle");
			iVehicle v = ((VehicleFactory) h).createVehicle(b ? "apc" : "tank", "", "", "");
			if (b) {
				APC ar = (APC) v;
				type.setText("���������������");
				name.setText(ar.name);
				fact.setText(ar.manufacturer);
				country.setText(ar.country);
				cal.setText(ar.caliber);

				sound1.setText("��������");
				sound2.setText("����");
			} else {
				Tank ar = (Tank) v;
				type.setText("����");
				name.setText(ar.name);
				fact.setText(ar.manufacturer);
				country.setText(ar.country);
				cal.setText(ar.caliber);

				sound1.setText("��������");
				sound2.setText("����");
			}
		}*/
	}
}