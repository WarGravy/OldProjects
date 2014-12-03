/**
 * Color Picker
 * Zachary Carlson
 */
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.event.*;
import java.util.Vector;
import java.io.File;
import java.io.FileWriter;
import java.io.FileNotFoundException;
import java.io.IOException; 
import java.util.Scanner;

@SuppressWarnings("unchecked")
public class ColorPicker extends JFrame{
	
	protected ColorPanel panelColor;
	protected JLabel labelR, labelG, labelB;
	protected JButton save, reset, rMinus, rPlus, gMinus, gPlus, bMinus, bPlus;
	protected JTextField tfRed, tfGreen, tfBlue;
	protected JList listColors;
	protected Graphics graphics;
	protected Vector<ColorSample> pallete;
	protected Vector<ColorSample> backupPallete;
	protected int lastPalleteIndex;
	protected String fTitle;
	
	public static void main(String[] args) {
		new ColorPicker("Color Picker Application");
	}

	public ColorPicker(String title) 
	{
		super(title);		// call constructor of base class
		fTitle = title;
		setSize(430, 450);
		addWindowListener(new WindowDestroyer());

		//initialize variables
		pallete = new Vector<ColorSample>();
		backupPallete = new Vector<ColorSample>();
		lastPalleteIndex = -1;
		//lists
		listColors = new JList();
		listColors.addListSelectionListener(new ListHandler());
		//buttons
		save = new JButton("Save");
		reset = new JButton("Reset");
		rMinus = new JButton("-");
		rPlus = new JButton("+");
		gMinus = new JButton("-");
		gPlus = new JButton("+");
		bMinus = new JButton("-");
		bPlus = new JButton("+");
		save.addActionListener(new ActionHandler());  
		reset.addActionListener(new ActionHandler());
		rMinus.addActionListener(new ActionHandler());  
		rPlus.addActionListener(new ActionHandler());
		gMinus.addActionListener(new ActionHandler());  
		gPlus.addActionListener(new ActionHandler());
		bMinus.addActionListener(new ActionHandler());  
		bPlus.addActionListener(new ActionHandler());
		//textfields
		tfRed = new JTextField("");
		tfGreen = new JTextField("");
		tfBlue = new JTextField("");
		//color panel
		panelColor = new ColorPanel();
		//labels
		labelR = new JLabel("Red:");
		labelG = new JLabel("Green:");
		labelB = new JLabel("Blue:");

		//layout
		getContentPane().setLayout(null);
		
		//color panel
		getContentPane().add(panelColor);
		panelColor.setBounds(10, 10, 280, 200);
		//list pane
		JScrollPane jscrollpane = new JScrollPane(listColors);
		getContentPane().add(jscrollpane);
		jscrollpane.setBounds(300, 10, 100, 380);
		//red row
		getContentPane().add(labelR);
		labelR.setBounds(30, 220, 50, 30);
		getContentPane().add(tfRed);
		tfRed.setBounds(90, 220, 50, 30);
		getContentPane().add(rMinus);
		rMinus.setBounds(150, 220, 50, 30);
		getContentPane().add(rPlus);
		rPlus.setBounds(210, 220, 50, 30);
		//green row
		getContentPane().add(labelG);
		labelG.setBounds(30, 260, 50, 30);
		getContentPane().add(tfGreen);
		tfGreen.setBounds(90, 260, 50, 30);
		getContentPane().add(gMinus);
		gMinus.setBounds(150, 260, 50, 30);
		getContentPane().add(gPlus);
		gPlus.setBounds(210, 260, 50, 30);
		//blue row
		getContentPane().add(labelB);
		labelB.setBounds(30, 300, 50, 30);
		getContentPane().add(tfBlue);
		tfBlue.setBounds(90, 300, 50, 30);
		getContentPane().add(bMinus);
		bMinus.setBounds(150, 300, 50, 30);
		getContentPane().add(bPlus);
		bPlus.setBounds(210, 300, 50, 30);
		//save and reset
		getContentPane().add(save);
		save.setBounds(50, 350, 70, 30);
		getContentPane().add(reset);
		reset.setBounds(150, 350, 70, 30);

		//build vector of colors
		readFile();
		Vector<String> colors = new Vector<String>();
		for(ColorSample sample : pallete){
			colors.add(new String(sample.name));
		}
		//set list data
		listColors.setListData(colors);

		//set data for RGB
        tfRed.setText("255");
        tfGreen.setText("255");
        tfBlue.setText("255");

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
			boolean flag = false;
			if ( e.getSource() == save )
			{
				saveFile();
				readFile();//update the backupPallete
				flag = true;
			}
			else if ( e.getSource() == reset ){
				System.out.println("You pressed the Reset button.");
				pallete.removeAllElements();
				for(ColorSample cs :backupPallete){
					pallete.add(new ColorSample(cs.name, cs.red, cs.green, cs.blue));
				}
				tfRed.setText(String.valueOf(pallete.get(lastPalleteIndex).red));
				tfBlue.setText(String.valueOf(pallete.get(lastPalleteIndex).blue));
				tfGreen.setText(String.valueOf(pallete.get(lastPalleteIndex).green));
				lastPalleteIndex = -1;

			}
			else if(e.getSource() == rMinus){
				tfRed.setText(ColorCounter(tfRed.getText(), false));

			}
			else if(e.getSource() == rPlus){
				tfRed.setText(ColorCounter(tfRed.getText(), true));
				
			}
			else if(e.getSource() == gMinus){
				tfGreen.setText(ColorCounter(tfGreen.getText(), false));
				
			}
			else if(e.getSource() == gPlus){
				tfGreen.setText(ColorCounter(tfGreen.getText(), true));
				
			}
			else if(e.getSource() == bMinus){
				tfBlue.setText(ColorCounter(tfBlue.getText(), false));
				
			}
			else if(e.getSource() == bPlus){
				tfBlue.setText(ColorCounter(tfBlue.getText(), true));
			}
			/*if(!flag && !fTitle.toLowerCase().contains("*") ){
				fTitle += " *";
				this.setTitle(fTitle);
			}*/
			panelColor.repaint();
		}
	} 
	// Define list listener                                       
	private class ListHandler implements ListSelectionListener 
	{      
		public void valueChanged(ListSelectionEvent e)
		{
		  if ( e.getSource() == listColors && !e.getValueIsAdjusting() )
		     {
		     	//store last values in color pallete
		     	if(lastPalleteIndex > -1){
		     		String temp = pallete.get(lastPalleteIndex).name;
		     		pallete.set(lastPalleteIndex, new ColorSample(temp, Integer.parseInt(tfRed.getText()),Integer.parseInt(tfGreen.getText()),Integer.parseInt(tfBlue.getText())));
		     	}
				int i = listColors.getSelectedIndex();
				lastPalleteIndex = i;
				String s = (String) listColors.getSelectedValue();
				System.out.println("Position " + i + " selected: " +s);

				//set values to the stored colors in the pallete
				tfBlue.setText(String.valueOf(pallete.get(i).blue));
				tfRed.setText(String.valueOf(pallete.get(i).red));
				tfGreen.setText(String.valueOf(pallete.get(i).green));
				panelColor.repaint();

		     }
		 
		}
	}
    //String to Int to String Color converter
    public String ColorCounter(String s, boolean addition){
    	int i = Integer.parseInt(s);
    	if(addition && i < 255){
    		i+=5;
    	}
    	else if(!addition && i > 0){
    		i-=5;
    	}
    	if(i > 255)
    		i = 255;
    	if(i < 0)
    		i = 0;
    	
    	return String.valueOf(i);
    } 
    //String to Int to String Color converter
    public void readFile(){
    	pallete.removeAllElements();
    	backupPallete.removeAllElements();
    	//read file and build list of ColorSamples
		File file = new File("save.txt");

    	try {

	        Scanner sc = new Scanner(file);

	        while (sc.hasNextLine()) {
	            String temp = sc.next();
	            int r = sc.nextInt();
	            int g = sc.nextInt();
	            int b = sc.nextInt();
	            System.out.println(temp);
	            System.out.println(r);
	            System.out.println(g);
	            System.out.println(b);
	            pallete.add(new ColorSample(temp,r,g,b));
	            backupPallete.add(new ColorSample(temp,r,g,b));
        	}
        	sc.close();
    	} 
		catch (IOException e) {
	        e.printStackTrace();
    	}
    } 
    class ColorPanel extends JComponent
	{
		public void paint(Graphics g)
		{
			Dimension d = getSize();

			g.setColor(new Color(Integer.parseInt(tfRed.getText()),Integer.parseInt(tfGreen.getText()),Integer.parseInt(tfBlue.getText())));
			g.fillRect(1, 1, d.width-2, d.height-2);
		
		}
	}
	public void saveFile(){
		try{
		FileWriter fw = new FileWriter("save.txt");
 		int i = 1;
		for (ColorSample cs: pallete ) {
			if(i != pallete.size()){
				fw.write(cs.name + " " + String.valueOf(cs.red) + " " + String.valueOf(cs.green) + " " +  String.valueOf(cs.blue) + "\n");
			}
			else{
				fw.write(cs.name + " " + String.valueOf(cs.red) + " " + String.valueOf(cs.green) + " " +  String.valueOf(cs.blue));
			}
			i++;
		}
	 
		fw.close();
		}
		catch (IOException e) {
	        e.printStackTrace();
    	}
	}
    class ColorSample
	{
		public int red;
		public int green;
		public int blue;
		public String name;

		public ColorSample(String title, int r, int g, int b){
			red = r;
			green = g;
			blue = b;
			name = title;
		}
 	}             
}
