package script;

public class Opening implements Script
{
	@Override
	public void run()
	{
		console.Console.clearConsole();
		String[] openingScript= {"태","초","의"," ","우","주","는"," ","공","허","했","다",".",".","."};
		for(int i=0; i<openingScript.length;i++)
		{
			System.out.print(openingScript[i]);
			try {
				Thread.sleep(100);
			} catch(InterruptedException e)
			{
				e.printStackTrace();
			}
		}
		
		try {
			Thread.sleep(500);
		} catch(InterruptedException e)
		{
			e.printStackTrace();
		}
		
		System.out.println("\n");
		
		String[] openingScript2= {"그","리","고"," ","이"," ","광","활","하","고"," ","허","무","한"," ","세","계","를"," ","정","처"," ","없","이"," ","떠","도","는"," ","초","월","적","인"," ","존","재","가"," ","있","었","다","."};
		for(int i=0; i<openingScript2.length;i++)
		{
			System.out.print(openingScript2[i]);
			try {
				Thread.sleep(100);
			} catch(InterruptedException e)
			{
				e.printStackTrace();
			}
		}
		try {
			Thread.sleep(500);
		} catch(InterruptedException e)
		{
			e.printStackTrace();
		}
		System.out.println("\n");
		String[] openingScript3= {
				"\r\n",
				"      ■                    ■\r\n",
				"      ■                    ■\r\n",
				"    ■  ■                ■  ■\r\n",
				"    ■  ■                ■  ■■\r\n",
				"    ■  ■                  ■    ■\r\n",
				"  ■■  ■                    ■■  ■\r\n",
				"  ■■  ■                    ■    ■\r\n",
				"  ■  ■■■                  ■  ■  ■\r\n",
				"    ■■    ■■                ■  ■  ■\r\n",
				"      ■  ■  ■■            ■■■    ■\r\n",
				"      ■■■  ■■      ■■■■  ■■  ■■\r\n",
				"        ■  ■  ■■■■■■■    ■■■  ■\r\n",
				"          ■  ■  ■■■■■■■    ■■  ■\r\n",
				"            ■■■          ■■■■■  ■■\r\n",
				"                ■  ■■          ■        ■\r\n",
				"              ■      ■■■■                ■\r\n",
				"              ■        ■▒▒■                ■\r\n",
				"              ■        ■▒■                    ■\r\n",
				"                ■      ■■                        ■\r\n",
				"                  ■■                                ■\r\n",
				"                ■    ■          ■■■  ■■■  ■    ■\r\n",
				"                ■      ■■■■■    ■  ■  ■  ■■■■\r\n",
				"                ■  ■    ■            ■      ■\r\n",
				"              ■    ■    ■                        \r\n",
				"              ■  ■■■    ■          ■  ■  ■  \r\n",
				"            ■    ■■■    ■■■■  ■  ■  ■  ■  ■\r\n",
				"          ■    ■■■  ■          ■■  ■  ■  ■■■■\r\n",
				"■■■■■    ■■■■    ■■                          ■\r\n",
				"              ■■■      ■■■■■■■■■■■■■■■\r\n",
				"                ■      ■            ■\r\n",
				"                      ■          ■■\r\n",
				"                    ■          ■\r\n",
				"            ■■■■            ■\r\n",
				"        ■■                ■■\r\n",
				"■■■■                ■■\r\n",
				"                    ■■\r\n",
				"              ■■■\r\n",
				"■■■■■■■\n"};
		for(int i=0; i<openingScript3.length;i++)
		{
			System.out.print(openingScript3[i]);
			try {
				Thread.sleep(100);
			} catch(InterruptedException e)
			{
				e.printStackTrace();
			}
		}
		System.out.println("");
		String[] openingScript4= {"아","우","렐","리","온"," ","솔","."};
		for(int i=0; i<openingScript4.length;i++)
		{
			System.out.print(openingScript4[i]);
			try {
				Thread.sleep(100);
			} catch(InterruptedException e)
			{
				e.printStackTrace();
			}
		}
		try {
			Thread.sleep(2000);
		} catch(InterruptedException e)
		{
			e.printStackTrace();
		}
	}
}
