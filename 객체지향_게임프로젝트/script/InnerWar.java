package script;

public class InnerWar implements Script {

	@Override
	public void run() 
	{
		String[] helpingScript= {"��","��","��","��"," ","��","��","��","��","��"," ","��","��","��","��","."};
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
		
		String[] helpingScript2= {"��","��","ü","��","��"," ","��","��"," ","��","��","��"," ","��","��","."};
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
		String[] helpingScript3= {"��","��"," ","��","��","��"," ","��","��","��"," ","��","��","��"," ","��","��","��"," ","��","��"," ","��","��","."};
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
		String[] helpingScript4= {"��"," ","��","��","ü","��"," ","��","��","¢","��","��",".",".","."};
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
		String[] helpingScript5= {"\"","õ","��","��"," ","��","��","��","��","!","!"," ","��","��"," ","��"," ","��","��","��"," ","��","��","��","��","��","��",".",".","!","\"","\n"};
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
		System.out.print("\n�����ֽðڽ��ϱ�? (Y/N)>> ");
	}
}
