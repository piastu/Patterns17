package cw;

import java.io.DataInputStream;
import java.io.DataOutputStream;

// Интерфейс для объектов, которые могут быть записаны и прочитаны из файла
public interface ISaveable {
	
	public void writeToFile(DataOutputStream out) throws Exception;
	
	public void readFromFile(DataInputStream in) throws Exception;
	
}
