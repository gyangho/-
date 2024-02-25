
import console.*;
import script.Opening;

public class Main 
{
	public static void main(String[] args) 
	{
		EndConsole end=new EndConsole();
		GalaxyConsole galaxy=new GalaxyConsole();
		ScreenConsole screen=new ScreenConsole();
		StatusConsole status=new StatusConsole();
		VisitConsole visit=new VisitConsole();
		screen.firstscreen();
		Opening opening=new Opening();
		opening.run();
		while(true)
		{
			switch(screen.Mainscreen())
			{
			case "1":
				galaxy.firstscreen();
				break;
			case "2":
				visit.firstscreen();
				break;
			case "3":
				break;
			case "4":
				status.firstscreen();
				break;
			case "e":
				end.Exit();
				break;
			default:
				break;
			}
		}
	}
}