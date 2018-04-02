package pat_kurs;

import java.util.ArrayList;

public abstract class aFirearm extends aWeapon implements iWeapon {
	ArrayList<String> attachments;
	
	aFirearm(String n, String c, String m, String cal) {
		super(n, c, m, cal);
		attachments = new ArrayList<String>();
	}
}
