package console;

public class ScreenConsole extends Console 
{
	@Override
	public void firstscreen() 
	{
		String input;
		clearConsole();
		String[] Startingscreen={
				"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\r\n" + 
				"■                                                                                                                  ■\r\n" + 
				"■                                                                                                                  ■\r\n" + 
				"■      ■■■■■        ■■■■■      ■          ■                                                            ■\r\n" + 
				"■    ■                ■                ■          ■                                                            ■\r\n" + 
				"■    ■                ■                ■          ■                                                            ■\r\n" + 
				"■      ■■■■■        ■■■■■      ■          ■                                                            ■\r\n" + 
				"■                ■                ■    ■          ■                                                            ■\r\n" + 
				"■                ■                ■    ■          ■                                                            ■\r\n" + 
				"■      ■■■■■        ■■■■■        ■■■■■                                                              ■\r\n" + 
				"■                                                                                                                  ■\r\n" + 
				"■                                                                                                                  ■\r\n" + 
				"■            ■        ■        ■        ■■■■■          ■■■■■■      ■              ■■■■■        ■\r\n" + 
				"■            ■        ■        ■      ■          ■      ■            ■    ■              ■        ■      ■\r\n" + 
				"■            ■        ■        ■    ■              ■    ■            ■    ■              ■          ■    ■\r\n" + 
				"■            ■        ■        ■    ■              ■    ■  ■■■■■      ■              ■          ■    ■\r\n" + 
				"■            ■        ■        ■    ■              ■    ■      ■          ■              ■          ■    ■\r\n" + 
				"■              ■    ■  ■    ■      ■              ■    ■        ■        ■              ■          ■    ■\r\n" + 
				"■              ■    ■  ■    ■        ■          ■      ■          ■      ■              ■        ■      ■\r\n" + 
				"■                ■■      ■■            ■■■■■        ■            ■    ■■■■■■    ■■■■■        ■\r\n" + 
				"■                                                                                                                  ■\r\n" + 
				"■                                                                                                                  ■\r\n" + 
				"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\r\n" + 
				"\r\n" + 
				""};
		for (int i=0;i<Startingscreen.length;i++)
			System.out.print(Startingscreen[i]);
		System.out.println("");
		System.out.println("게임을 시작하시겠습니까?");
		System.out.print("Y/N> ");
		input=Input();
		if(input.equals("Y")||input.equals("y"))
			return;
		else
			System.exit(0);
	}
	public String Mainscreen()
	{
		String num_s;
		clearConsole();
		String[] mainscreen= {
				"      ■                    ■\r\n" + 
				"      ■                    ■\r\n" + 
				"    ■▒■                ■▒■\r\n" + 
				"    ■▒■                ■▒■■\r\n" + 
				"    ■▒■                  ■▒▒■\r\n" + 
				"  ■■▒■                    ■■▒■\r\n" + 
				"  ■■▒■                    ■▒▒■\r\n" + 
				"  ■▒■■■                  ■▒■▒■\r\n" + 
				"    ■■▒▒■■                ■▒■▒■\r\n" + 
				"      ■▒■▒■■            ■■■▒▒■\r\n" + 
				"      ■■■▒■■      ■■■■▒■■▒■■                                        ■■■■■■■■■■■■■■■■■■\r\n" + 
				"        ■▒■▒■■■■■■■▒▒■■■▒■                                        ■                                ■\r\n" + 
				"          ■▒■▒■■■■■■■▒▒■■▒■                                        ■                                ■        \r\n" + 
				"            ■■■          ■■■■■  ■■                                        ■      ①. 항성 생성하기         ■        \r\n" + 
				"                ■  ■■          ■        ■                                      ■                                ■          \r\n" + 
				"              ■      ■■■■                ■                                    ■      ②. 항성 방문하기         ■          \r\n" + 
				"              ■        ■▒▒■                ■                                  ■                                ■              \r\n" + 
				"              ■        ■▒■                    ■                                ■      ③. 항성 파괴하기         ■\r\n" + 
				"                ■      ■■                      ■■                              ■                                ■\r\n" + 
				"                  ■■                                ■                            ■      ④. 현재 상태보기         ■\r\n" + 
				"                ■    ■          ■■■  ■  ■  ■    ■                          ■                                ■\r\n" + 
				"                ■      ■■■■■▒▒■  ■  ■  ■■■■                          ■      ⓔ. 게임 종료하기         ■\r\n" + 
				"              ■  ■    ■▒▒▒▒▒▒▒■▒■▒■                                  ■                                ■\r\n" + 
				"              ■    ■    ■▒▒▒▒▒▒▒▒▒▒▒                                  ■                                ■\r\n" + 
				"              ■  ■■■    ■▒▒▒▒▒■▒■▒■                                  ■■■■■■■■■■■■■■■■■■\r\n" + 
				"            ■    ■■■    ■■■▒▒■  ■  ■  ■  ■                          \r\n" + 
				"          ■    ■■■  ■      ■■■■  ■  ■  ■■■■                          \r\n" + 
				"■■■■■    ■■■■    ■■                          ■                                                                                                                \r\n" + 
				"              ■■■      ■■■■■■■■■■■■■■■\r\n" + 
				"                ■      ■            ■\r\n" + 
				"                      ■          ■■\r\n" + 
				"                    ■          ■\r\n" + 
				"            ■■■■            ■\r\n" + 
				"        ■■                ■■\r\n" + 
				"■■■■                ■■\r\n" + 
				"                    ■■\r\n" + 
				"              ■■■\r\n" + 
				"■■■■■■■"
		};
		System.out.println("현재 년도: "+Century+" C\n\n");
		for (int i=0;i<mainscreen.length;i++)
			System.out.print(mainscreen[i]);
		System.out.println("\n\n\n");
		System.out.println("아우렐리온 솔 : 뭐하지");
		System.out.print("입력하세요 >> ");
		num_s=Input();
		return num_s;
	}
}