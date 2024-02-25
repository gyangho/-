package console;

public class GalaxyConsole extends Console
{
	@Override
	public void firstscreen()
	{
		int num;
		String[] Stararr= {"M","K","G","F","A","B","O"};
		String[] selectingscreen= {"\n\n\n\n\n"
				+ "                                        #1 M형 항성\r\n\n"
				+ "                                        #2 K형 항성\r\n\n"
				+ "                                        #3 G형 항성\r\n\n"
				+ "                                        #4 F형 항성\r\n\n"
				+ "                                        #5 A형 항성\r\n\n"
				+ "                                        #6 B형 항성\r\n\n"
				+ "                                        #7 O형 항성\r\n\n"
				+ "                                        #8  도움말\r\n\n"
				+ "\n\n\n\n                                        다른 키+Enter를 누르면 메인메뉴로 이동합니다."
		};
		clearConsole();
		for (int i=0; i<selectingscreen.length;i++)
			System.out.print(selectingscreen[i]);
		System.out.println("\n\n\n");
		System.out.println("아우렐리온 솔: 힘 조절을 어떻게할까...\n");
		System.out.print("숫자를 입력해주세요 >>");
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
			System.out.println("\n항성 만들기 성공..!");
			System.out.println("행성이 하나 만들어졌습니다! 이름을 지어주세요>>");
			String Planetname=Input();
			for (int i=0; i<PlanetList.size();i++)
			{
				if(Planetname.equals(PlanetList.get(i)[2]))
				{
						System.out.println("이미 존재하는 행성 이름입니다. 다시 입력해주세요.");
						Planetname=Input();
						i=0;
				}
			}
			String[] Content= {String.valueOf(Century),startype,Planetname,"?","?"};
			PlanetList.add(Content);
		}
		else if (success=="Fail")
		{
			System.out.println("\n항성 만들기 실패..!\n");
		}
		System.out.println("\n시간이 1C만큼 지났습니다.\n");
		Century++;
		System.out.println("===============================================================================s");
		System.out.println("ENTER를 입력해주세요.");
		Input();
	}
}