package console;

public class EndConsole extends Console
{
	public void Exit()
	{
		while(true)
		{
			Console.clearConsole();
			for (int i=0; i<15;i++)
				System.out.println();
			System.out.println("                          게임을 종료할까요?\n");
			System.out.println("                           예(1) / 아니오(2)\n");
			System.out.print("                          >>");
			String num=Console.Input();
			if (num.equals("1"))
				System.exit(0);
			else if(num.equals("2"))
				break;
		}
	}
	
	@Override
	public void firstscreen() 
	{
		
	}
}