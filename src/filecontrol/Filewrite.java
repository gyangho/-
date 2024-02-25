package filecontrol;

import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;

public class Filewrite {
	protected String fileContent;
	protected String fileName;
	FileWriter fr;
	BufferedWriter wr;
	protected void Writing()
	{
		try 
		{
			fr=new FileWriter(fileName,true);
			wr=new BufferedWriter(fr);
			wr.write(fileContent);
			wr.newLine();
			wr.close();
			fr.close();
		} 
		catch (FileNotFoundException e) 
		{
			e.printStackTrace();
		}
		catch (IOException ioe) {}
	}
}
