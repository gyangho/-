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
		String[] helpScript= {"\n","행","성","주","변","에"," ","두"," ","우","주","선","이"," ","마","주"," ","서","있","다",".","\n"};
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
		
		String[] helpScript2= {"\n","크","고"," ","작","은"," ","불","꽃","이"," ","피","어","오","르","고"," ","비","명","소","리","가"," ","들","려","온","다",".","\n"};
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
		
		String[] helpScript3= {"\n","<",Pl1,">","행","성"," ","생","명","체",":"," ","\"","공","격","하","라","!","!","!"," ","우","리","의"," ","영","역","을"," ","침","범","한"," ","미","개","한"," ","외","계","생","명","체","를"," ","박","멸","하","라","!","\"","\n"};
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
		
		String[] helpScript4= {"\n","<",Pl2,">","행","성"," ","생","명","체",":"," ","\"","목","숨","을"," ","바","치","고"," ","막","아","라","!"," ","우","리","의"," ","영","역","을"," ","지","켜","라","!","\"","\n"};
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
		
		String[] helpScript5= {"\n",Pl1,"행","성","과"," ",Pl2,"행","성","이"," ","영","역"," ","분","쟁","을"," ","하","고"," ","있","다",".","\n"};
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
		System.out.print("어느 쪽을 도와주시겠습니까? (전자 생명체[Y]/후자 생명체[N])>> ");
	}

}
