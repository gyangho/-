package script;

public class Opening implements Script
{
	@Override
	public void run()
	{
		console.Console.clearConsole();
		String[] openingScript= {"��","��","��"," ","��","��","��"," ","��","��","��","��",".",".","."};
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
		
		String[] openingScript2= {"��","��","��"," ","��"," ","��","Ȱ","��","��"," ","��","��","��"," ","��","��","��"," ","��","ó"," ","��","��"," ","��","��","��"," ","��","��","��","��"," ","��","��","��"," ","��","��","��","."};
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
				"      ��                    ��\r\n",
				"      ��                    ��\r\n",
				"    ��  ��                ��  ��\r\n",
				"    ��  ��                ��  ���\r\n",
				"    ��  ��                  ��    ��\r\n",
				"  ���  ��                    ���  ��\r\n",
				"  ���  ��                    ��    ��\r\n",
				"  ��  ����                  ��  ��  ��\r\n",
				"    ���    ���                ��  ��  ��\r\n",
				"      ��  ��  ���            ����    ��\r\n",
				"      ����  ���      �����  ���  ���\r\n",
				"        ��  ��  ��������    ����  ��\r\n",
				"          ��  ��  ��������    ���  ��\r\n",
				"            ����          ������  ���\r\n",
				"                ��  ���          ��        ��\r\n",
				"              ��      �����                ��\r\n",
				"              ��        ��Ƣơ�                ��\r\n",
				"              ��        ��ơ�                    ��\r\n",
				"                ��      ���                        ��\r\n",
				"                  ���                                ��\r\n",
				"                ��    ��          ����  ����  ��    ��\r\n",
				"                ��      ������    ��  ��  ��  �����\r\n",
				"                ��  ��    ��            ��      ��\r\n",
				"              ��    ��    ��                        \r\n",
				"              ��  ����    ��          ��  ��  ��  \r\n",
				"            ��    ����    �����  ��  ��  ��  ��  ��\r\n",
				"          ��    ����  ��          ���  ��  ��  �����\r\n",
				"������    �����    ���                          ��\r\n",
				"              ����      ����������������\r\n",
				"                ��      ��            ��\r\n",
				"                      ��          ���\r\n",
				"                    ��          ��\r\n",
				"            �����            ��\r\n",
				"        ���                ���\r\n",
				"�����                ���\r\n",
				"                    ���\r\n",
				"              ����\r\n",
				"��������\n"};
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
		String[] openingScript4= {"��","��","��","��","��"," ","��","."};
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
