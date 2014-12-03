/**
 * Color Picker
 * Zachary Carlson
 */
import java.awt.*;
import javax.swing.*; 
import java.awt.event.*;

public class ColorPicker extends JFrame{
	
	protected JButton buttonDone;
	protected JButton buttonCancel;
	protected JTextField tfFirstName;
	protected JTextField tfLastName;

	public static void main(String[] args) {
		new ColorPicker("Color Picker Application");
	}

	public ColorPicker(String title) 
	{
		super(title);		// call constructor of base class
		setSize(350, 150);
		//setBounds(100, 100, 250, 100);

		addWindowListener(new WindowDestroyer());

		buttonDone = new JButton("Done");
		buttonCancel = new JButton("Cancel");
		buttonDone.addActionListener(new ActionHandler());  
		buttonCancel.addActionListener(new ActionHandler());

		tfFirstName = new JTextField("");
		tfLastName = new JTextField("");

		getContentPane().setLayout(new GridLayout(3, 2));
		getContentPane().add(new JLabel("First Name:"));
		getContentPane().add(tfFirstName);
		getContentPane().add(new JLabel("Last Name:"));
		getContentPane().add(tfLastName);
		getContentPane().add(buttonDone);
		getContentPane().add(buttonCancel);
		
        tfFirstName.setText("John");
        tfLastName.setText("John");

		setVisible(true);
	}

	private class WindowDestroyer extends WindowAdapter 
	{      
		// implement only the function that you want
		public void windowClosing(WindowEvent e) 
		{    
			System.exit(0);  
		}                                                             
	}                                                              

	// Define action listener                                       
	private class ActionHandler implements ActionListener 
	{      
		public void actionPerformed(ActionEvent e)
		{
			if ( e.getSource() == buttonDone )
			{
				String s1 = tfFirstName.getText();
				String s2 = tfLastName.getText();
				System.out.println("Full name: " + s1 + " " + s2);
			}
			else if ( e.getSource() == buttonCancel )
				System.out.println("You pressed the Cancel button.");
		}
	}                        

}
