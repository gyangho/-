package filecontrol;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Vector;

public class Fileread {
	protected Vector<String> content=new Vector<String>(5);
	protected String fileName = null;
	FileInputStream fr;
	BufferedReader br;
	protected void readFile() 
	{
		String line = null;
		 try
		 {
			 fr = new FileInputStream(fileName);
			 InputStreamReader ip=new InputStreamReader(fr,"UTF-8");
			 br = new BufferedReader(ip);
			 while((line=br.readLine()) != null)
			 {
				 line = line.trim();
				 if(line.length() != 0)
					 content.add(line);
			 }
			 fr.close();
			 br.close();
		 }
		 catch(FileNotFoundException fnfe)
		 {
	            System.out.println(fileName + " : CAN'T FOUND");
		 }
		 catch(IOException ioe){}
	}
}
