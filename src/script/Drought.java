package script;

public class Drought implements Script
{
	@Override
	public void run() 
	{
		String[] helpingScript= {"생","명","체","들","이"," ","모","여"," ","의","식","을"," ","치","루","고"," ","있","다","."};
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
		String[] helpingScript2= {"굶","주","려"," ","보","이","고",", ","땅","들","은"," ","수","분","이"," ","없","어"," ","갈","라","져","있","다","."};
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
		String[] helpingScript3= {"가","뭄","이"," ","일","어","난"," ","것"," ","같","다",".","\n"};
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
		String[] helpingScript4= {"\n","\"","천","상","의"," ","용","이","시","여",", ","저","희","의"," ","제","물","을"," ","받","아","주","시","고"," ","비","가"," ","내","리","게"," ","해","주","십","시","오",".","\"","\n"};
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
		System.out.print("도와주시겠습니까? (Y/N)>> ");
	}
}
