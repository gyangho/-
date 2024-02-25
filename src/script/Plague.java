package script;

public class Plague implements Script {

	@Override
	public void run() 
	{
		String[] helpingScript= {"\n","생","명","체","가"," ","잘"," ","보","이","지"," ","않","는","다",".","\n"};
		for(int i=0; i<helpingScript.length;i++)
		{
			System.out.print(helpingScript[i]);
			try 
			{
				Thread.sleep(100);
			} 
			catch(InterruptedException e)
			{
				e.printStackTrace();
			}
		}
		try 
		{
			Thread.sleep(500);
		} 
		catch(InterruptedException e)
		{
			e.printStackTrace();
		}
		
		String[] helpingScript2= {"\n","몇","몇"," ","개","체","들","이"," ","모","여"," ","의","식","을"," ","치","루","고","있","다",".","\n"};
		for(int i=0; i<helpingScript2.length;i++)
		{
			System.out.print(helpingScript2[i]);
			try 
			{
				Thread.sleep(100);
			} 
			catch(InterruptedException e)
			{
				e.printStackTrace();
			}
		}
		try 
		{
			Thread.sleep(500);
		} 
		catch(InterruptedException e)
		{
			e.printStackTrace();
		}
		
		String[] helpingScript3= {"\n","\"","천","상","의"," ","용","이","시","여",","," ","저","희","를"," ","재","앙","으","로","부","터"," ","지","켜","주","십","시","오",".","\"","\n"};
		for(int i=0; i<helpingScript3.length;i++)
		{
			System.out.print(helpingScript3[i]);
			try 
			{
				Thread.sleep(100);
			} 
			catch(InterruptedException e)
			{
				e.printStackTrace();
			}
		}
		System.out.println("");
		System.out.print("ENTER를 눌러주세요.>> ");
	}
}
