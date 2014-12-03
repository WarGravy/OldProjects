/**
 * Color Picker
 * Zachary Carlson
 */
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.event.*;

@SuppressWarnings("unchecked")
public class ColorPicker extends JFrame{
	
	protected JButton buttonDone, buttonCancel;
	protected JTextField tfFirstName, tfLastName;
	protected JList listColors;

	public static void main(String[] args) {
		new ColorPicker("Color Picker Application");
	}

	public ColorPicker(String title) 
	{
		super(title);		// call constructor of base class
		setSize(500, 200);
		//setBounds(100, 100, 250, 100);

		addWindowListener(new WindowDestroyer());

		listColors = new JList();
		listColors.addListSelectionListener(new ListHandler());

		buttonDone = new JButton("Done");
		buttonCancel = new JButton("Cancel");
		buttonDone.addActionListener(new ActionHandler());  
		buttonCancel.addActionListener(new ActionHandler());

		tfFirstName = new JTextField("");
		tfLastName = new JTextField("");

		getContentPane().setLayout(new GridLayout(5, 2));
		getContentPane().add(new JLabel("First Name:"));
		getContentPane().add(tfFirstName);
		getContentPane().add(new JLabel("Last Name:"));
		getContentPane().add(tfLastName);
		getContentPane().add(buttonDone);
		getContentPane().add(buttonCancel);
		getContentPane().add(new JScrollPane(listColors));

		String colors[] = {"Red", "Green", "Blue", "Yellow", "Cyan", "Magenta", "Orange", "Pink", "Grey", "Black", "White"};
		listColors.setListData(colors);
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
	// Define list listener                                       
	private class ListHandler implements ListSelectionListener 
	{      
		public void valueChanged(ListSelectionEvent e)
		{
		  if ( e.getSource() == listColors && !e.getValueIsAdjusting() )
		     {
				int i = listColors.getSelectedIndex();
				String s = (String) listColors.getSelectedValue();
				System.out.println("Position " + i + " selected: " +s);
		     }
		 
		}
	}
                       
}
