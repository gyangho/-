package script;

public class War implements Script 
{
	String Pl1,Pl2;
	public War(String str1, String str2)
	{
		Pl1=str1;
		Pl2=str2;
	}

	@Override
	public void run() 
	{
		String[] helpScript= {"\n","��","��","��","��","��"," ","��"," ","��","��","��","��"," ","��","��"," ","��","��","��",".","\n"};
		for(int i=0; i<helpScript.length;i++)
		{
			System.out.print(helpScript[i]);
			try {
				Thread.sleep(100);
			} catch(InterruptedException e)
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
		
		String[] helpScript2= {"\n","ũ","��"," ","��","��"," ","��","��","��"," ","��","��","��","��","��"," ","��","��","��","��","��"," ","��","��","��","��",".","\n"};
		for(int i=0; i<helpScript2.length;i++)
		{
			System.out.print(helpScript2[i]);
			try {
				Thread.sleep(100);
			} catch(InterruptedException e)
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
		
		String[] helpScript3= {"\n","<",Pl1,">","��","��"," ","��","��","ü",":"," ","\"","��","��","��","��","!","!","!"," ","��","��","��"," ","��","��","��"," ","ħ","��","��"," ","��","��","��"," ","��","��","��","��","ü","��"," ","��","��","��","��","!","\"","\n"};
		for(int i=0; i<helpScript3.length;i++)
		{
			System.out.print(helpScript3[i]);
			try {
				Thread.sleep(100);
			} catch(InterruptedException e)
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
		
		String[] helpScript4= {"\n","<",Pl2,">","��","��"," ","��","��","ü",":"," ","\"","��","��","��"," ","��","ġ","��"," ","��","��","��","!"," ","��","��","��"," ","��","��","��"," ","��","��","��","!","\"","\n"};
		for(int i=0; i<helpScript4.length;i++)
		{
			System.out.print(helpScript4[i]);
			try {
				Thread.sleep(100);
			} catch(InterruptedException e)
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
		
		String[] helpScript5= {"\n",Pl1,"��","��","��"," ",Pl2,"��","��","��"," ","��","��"," ","��","��","��"," ","��","��"," ","��","��",".","\n"};
		for(int i=0; i<helpScript5.length;i++)
		{
			System.out.print(helpScript5[i]);
			try {
				Thread.sleep(100);
			} catch(InterruptedException e)
			{
				e.printStackTrace();
			}
		}
		System.out.println("");
		System.out.print("��� ���� �����ֽðڽ��ϱ�? (���� ����ü[Y]/���� ����ü[N])>> ");
	}

}
