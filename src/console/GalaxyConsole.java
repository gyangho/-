package console;

public class GalaxyConsole extends Console
{
	@Override
	public void firstscreen()
	{
		int num;
		String[] Stararr= {"M","K","G","F","A","B","O"};
		String[] selectingscreen= {"\n\n\n\n\n"
				+ "                                        #1 M�� �׼�\r\n\n"
				+ "                                        #2 K�� �׼�\r\n\n"
				+ "                                        #3 G�� �׼�\r\n\n"
				+ "                                        #4 F�� �׼�\r\n\n"
				+ "                                        #5 A�� �׼�\r\n\n"
				+ "                                        #6 B�� �׼�\r\n\n"
				+ "                                        #7 O�� �׼�\r\n\n"
				+ "                                        #8  ����\r\n\n"
				+ "\n\n\n\n                                        �ٸ� Ű+Enter�� ������ ���θ޴��� �̵��մϴ�."
		};
		clearConsole();
		for (int i=0; i<selectingscreen.length;i++)
			System.out.print(selectingscreen[i]);
		System.out.println("\n\n\n");
		System.out.println("�ƿ췼���� ��: �� ������ ����ұ�...\n");
		System.out.print("���ڸ� �Է����ּ��� >>");
		try 
		{
			num=Integer.parseInt(Input());
			make(Stararr[num-1]);
		} 
		catch(NumberFormatException e)
		{
			return;
		}
	}
	static void make(String startype)
	{
		System.out.println("===============================================================================\n");
		Lottery Star=new Lottery("./Starpercentage.txt",startype,0);
		String success=Star.rand(1000);
		if (success=="Success")
		{
			System.out.println("\n�׼� ����� ����..!");
			System.out.println("�༺�� �ϳ� ����������ϴ�! �̸��� �����ּ���>>");
			String Planetname=Input();
			for (int i=0; i<PlanetList.size();i++)
			{
				if(Planetname.equals(PlanetList.get(i)[2]))
				{
						System.out.println("�̹� �����ϴ� �༺ �̸��Դϴ�. �ٽ� �Է����ּ���.");
						Planetname=Input();
						i=0;
				}
			}
			String[] Content= {String.valueOf(Century),startype,Planetname,"?","?"};
			PlanetList.add(Content);
		}
		else if (success=="Fail")
		{
			System.out.println("\n�׼� ����� ����..!\n");
		}
		System.out.println("\n�ð��� 1C��ŭ �������ϴ�.\n");
		Century++;
		System.out.println("===============================================================================s");
		System.out.println("ENTER�� �Է����ּ���.");
		Input();
	}
}