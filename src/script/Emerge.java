package script;

public class Emerge implements Script {

	@Override
	public void run() 
	{
		String[] helpingScript= {"\n","��","��","��"," ","��","��","��","��"," ","��","��","��"," ","��","��","��"," ","��","��"," ","��","��","��"," ","��","��","��"," ","��","��","Ų","��",".","\n"};
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
		
		String[] helpingScript2= {"\n","\"","��","��","��","!","\"","\n"};
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
		
		String[] helpingScript3= {"\n","\"","��","��","��","��",".",".","!","\"","\n"};
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
		System.out.print("ENTER�� �����ּ���.>> ");
	}
}
