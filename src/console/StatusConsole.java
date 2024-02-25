package console;

public class StatusConsole extends Console
{
	@Override
	public void firstscreen() 
	{
		clearConsole();
		System.out.println("\n\n\n\n");
		System.out.println("===============================================================================\n");
		System.out.println("<#Index> <생성시기[C]> <행성type> <행성이름> <생명체> <친밀도> 순서입니다.");
		System.out.println("<생명체>: 아직 존재하는지 모른다면 ?로 표시됩니다.");
		System.out.println("          (생명체 등급).(생명체이름)으로 표시됩니다.");
		System.out.println("<친밀도>: 아직 생명체가 존재하지 않는다면 ?로 표시됩니다.\n\n");
		for (int i=0; i<PlanetList.size();i++)
		{
			System.out.print("#"+(i+1)+"   ");
			for (int j=0;j<5;j++)
				System.out.print(PlanetList.get(i)[j]+"    ");
			System.out.println("\n");
		}
		System.out.println("\n===============================================================================");
		System.out.println("ENTER를 입력해주세요.");
		Input();
	}
}
