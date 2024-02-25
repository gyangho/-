package console;

import java.io.*;
import java.util.*;

public abstract class Console 
{
	static int Century=0;
	static int EndingC=100;
	static ArrayList<String[]> PlanetList=new ArrayList<String[]>(5);
	
	abstract public void firstscreen();
	public final static void clearConsole()
	{
		 try {
		        if (System.getProperty("os.name").contains("Windows"))
		            new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
		        else
		            Runtime.getRuntime().exec("clear");
		    } catch (IOException | InterruptedException ex) {}
	}
	public static String Input()
	{
		Scanner scanner=new Scanner(System.in);
		String input=scanner.nextLine();
		//scanner.close();
		return input;
	}
}	