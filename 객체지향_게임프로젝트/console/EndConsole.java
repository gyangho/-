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
			System.out.println("                          ������ �����ұ��?\n");
			System.out.println("                           ��(1) / �ƴϿ�(2)\n");
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