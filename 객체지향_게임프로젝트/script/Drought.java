package script;

public class Drought implements Script
{
	@Override
	public void run() 
	{
		String[] helpingScript= {"��","��","ü","��","��"," ","��","��"," ","��","��","��"," ","ġ","��","��"," ","��","��","."};
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
		String[] helpingScript2= {"��","��","��"," ","��","��","��",", ","��","��","��"," ","��","��","��"," ","��","��"," ","��","��","��","��","��","."};
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
		String[] helpingScript3= {"��","��","��"," ","��","��","��"," ","��"," ","��","��",".","\n"};
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
		String[] helpingScript4= {"\n","\"","õ","��","��"," ","��","��","��","��",", ","��","��","��"," ","��","��","��"," ","��","��","��","��","��"," ","��","��"," ","��","��","��"," ","��","��","��","��","��",".","\"","\n"};
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
		System.out.print("\n");
		System.out.print("�����ֽðڽ��ϱ�? (Y/N)>> ");
	}
}
