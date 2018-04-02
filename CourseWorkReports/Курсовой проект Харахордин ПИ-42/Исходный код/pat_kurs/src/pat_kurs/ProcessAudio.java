package pat_kurs;

import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;

import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.UnsupportedAudioFileException;

public class ProcessAudio {
	static aWeapon ProcessAudio(String filepath) throws IOException {
		AbstractFactory f = new FactoryProducer().getFactory("weapon");
		AbstractFactory h = new FactoryProducer().getFactory("vehicle");
		ArrayList<aWeapon> weaponList = new ArrayList<aWeapon>();
		weaponList.addAll(f.WeaponList());
		weaponList.addAll(h.WeaponList());
		
		File file = new File(filepath);
		AudioInputStream in;
		try {
			in = AudioSystem.getAudioInputStream(file);
			AudioFormat baseFormat = in.getFormat();
			AudioFormat decodedFormat = new AudioFormat(AudioFormat.Encoding.PCM_UNSIGNED, 
			                                            baseFormat.getSampleRate(),
			                                            16,
			                                            baseFormat.getChannels(),
			                                            baseFormat.getChannels() * 2,
			                                            baseFormat.getSampleRate(),
			                                            false);
			AudioInputStream din = AudioSystem.getAudioInputStream(decodedFormat, in);
			byte[] bb = din.readAllBytes();
//			System.out.println(decodedFormat.getFrameSize());
			int mid = -1;
			for (int i = 0; i < bb.length; i+=2) {
				int b1 = (int) (bb[i] & 0xff);
				int b2 = (int) (bb[i+1] & 0xff);
				int ref = b1;
				if (ref == -1)
			          break;
	            ref |= b2 << 8;
	            
				if (mid == -1)
					mid = ref;
				else
					mid = (mid + ref)/2;
			}
			
			int dif = Integer.MAX_VALUE;
			aWeapon difwep = null;
			
			for (aWeapon wep : weaponList)
				if (Math.abs(mid - wep.ampl) < dif) {
					dif = Math.abs(mid - wep.ampl);
					difwep = wep;
				}
			return difwep;
		} catch (UnsupportedAudioFileException e) {
			System.out.println("UnsupportedAudioFileException");
//			e.printStackTrace();
		}
		return null;
	}
}
