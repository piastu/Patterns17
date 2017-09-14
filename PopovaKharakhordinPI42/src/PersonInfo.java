package p2016;

import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JScrollPane;
import javax.swing.JCheckBox;
import javax.swing.JTextField;
import javax.swing.WindowConstants;
import javax.swing.JLabel;
import java.awt.event.FocusAdapter;
import java.awt.event.FocusEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class PersonInfo {

	public JFrame frame;
	public JTextField cashField;
	public JTextField creditField;
	public JTextArea log;
	public JCheckBox wantsToEat;
	public JCheckBox wantsToDrink;
	public JCheckBox hasCloth;
	public JCheckBox checkCoatRoom;
	
	public Person person;
	public JTextField printField;
	private JLabel label_2;
	
	/**
	 * Create the application.
	 */
	public PersonInfo() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosed(WindowEvent arg0) {
				person.isSelected = false;
			}
		});
		frame.addFocusListener(new FocusAdapter() {
			@Override
			public void focusLost(FocusEvent arg0) {
			}
		});
		frame.setResizable(false);
		frame.setBounds(100, 100, 602, 311);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		frame.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
		
		log = new JTextArea();
		log.setWrapStyleWord(true);
		log.setEditable(false);
		log.setBounds(10, 11, 200, 250);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(10, 11, 352, 250);
		scrollPane.setViewportView(log);
		frame.getContentPane().add(scrollPane);
		
		wantsToEat = new JCheckBox("\u0445\u043E\u0447\u0435\u0442 \u0435\u0441\u0442\u044C");
		wantsToEat.setEnabled(false);
		wantsToEat.setBounds(368, 11, 200, 23);
		frame.getContentPane().add(wantsToEat);
		
		wantsToDrink = new JCheckBox("\u0445\u043E\u0447\u0435\u0442 \u043F\u0438\u0442\u044C");
		wantsToDrink.setEnabled(false);
		wantsToDrink.setBounds(368, 37, 200, 23);
		frame.getContentPane().add(wantsToDrink);
		
		hasCloth = new JCheckBox("\u0435\u0441\u0442\u044C \u043A\u0443\u0440\u0442\u043A\u0430 \u0441 \u0441\u043E\u0431\u043E\u0439");
		hasCloth.setEnabled(false);
		hasCloth.setBounds(368, 63, 200, 23);
		frame.getContentPane().add(hasCloth);
		
		checkCoatRoom = new JCheckBox("\u0441\u0434\u0430\u0432\u0430\u043B \u043A\u0443\u0440\u0442\u043A\u0443 \u0432 \u0433\u0430\u0440\u0434\u0435\u0440\u043E\u0431");
		checkCoatRoom.setEnabled(false);
		checkCoatRoom.setBounds(368, 89, 200, 23);
		frame.getContentPane().add(checkCoatRoom);
		
		cashField = new JTextField();
		cashField.setEditable(false);
		cashField.setBounds(371, 244, 100, 20);
		frame.getContentPane().add(cashField);
		cashField.setColumns(10);
		
		creditField = new JTextField();
		creditField.setEditable(false);
		creditField.setColumns(10);
		creditField.setBounds(476, 244, 100, 20);
		frame.getContentPane().add(creditField);
		
		JLabel label = new JLabel("\u041D\u0430\u043B\u0438\u0447\u043D\u044B\u0435 \u0434\u0435\u043D\u044C\u0433\u0438");
		label.setBounds(372, 225, 90, 14);
		frame.getContentPane().add(label);
		
		JLabel label_1 = new JLabel("\u0414\u0435\u043D\u044C\u0433\u0438 \u043D\u0430 \u043A\u0430\u0440\u0442\u0435");
		label_1.setBounds(476, 225, 90, 14);
		frame.getContentPane().add(label_1);
		
		printField = new JTextField();
		printField.setEditable(false);
		printField.setColumns(10);
		printField.setBounds(371, 194, 100, 20);
		frame.getContentPane().add(printField);
		
		label_2 = new JLabel("\u041D\u0443\u0436\u043D\u043E \u0440\u0430\u0441\u043F\u0435\u0447\u0430\u0442\u0430\u0442\u044C \u043B\u0438\u0441\u0442\u043E\u0432");
		label_2.setBounds(372, 173, 179, 14);
		frame.getContentPane().add(label_2);
	}
}
