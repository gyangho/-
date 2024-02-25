package script;

public class Emerge implements Script {

	@Override
	public void run() 
	{
		String[] helpingScript= {"\n","행","성","에"," ","도","달","하","자"," ","몇","몇","이"," ","하","늘","을"," ","보","고"," ","놀","라","며"," ","허","공","을"," ","가","리","킨","다",".","\n"};
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
		
		String[] helpingScript2= {"\n","\"","용","이","다","!","\"","\n"};
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
		
		String[] helpingScript3= {"\n","\"","신","이","시","여",".",".","!","\"","\n"};
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
