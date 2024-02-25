package script;

public class InnerWar implements Script {

	@Override
	public void run() 
	{
		String[] helpingScript= {"지","상","에","서"," ","비","명","소","리","가"," ","들","려","온","다","."};
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
		System.out.println("\n");
		
		String[] helpingScript2= {"생","명","체","들","이"," ","서","로"," ","죽","이","고"," ","있","다","."};
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
		System.out.println("\n");
		String[] helpingScript3= {"종","족"," ","내","에","서"," ","분","열","이"," ","일","어","나"," ","내","전","을"," ","하","고"," ","있","다","."};
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
		try 
		{
			Thread.sleep(500);
		} 
		catch(InterruptedException e)
		{
			e.printStackTrace();
		}
		System.out.println("\n");
		String[] helpingScript4= {"한"," ","생","명","체","가"," ","울","부","짖","는","다",".",".","."};
		for(int i=0; i<helpingScript4.length;i++)
		{
			System.out.print(helpingScript4[i]);
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
		System.out.println("\n");
		String[] helpingScript5= {"\"","천","상","의"," ","용","이","시","여","!","!"," ","제","발"," ","이"," ","전","쟁","을"," ","끝","내","주","십","시","오",".",".","!","\"","\n"};
		for(int i=0; i<helpingScript5.length;i++)
		{
			System.out.print(helpingScript5[i]);
			try 
			{
				Thread.sleep(100);
			}
			catch(InterruptedException e)
			{
				e.printStackTrace();
			}	
		}
		System.out.print("\n도와주시겠습니까? (Y/N)>> ");
	}
}
