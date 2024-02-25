package console;

public class StatusConsole extends Console
{
	@Override
	public void firstscreen() 
	{
		clearConsole();
		System.out.println("\n\n\n\n");
		System.out.println("===============================================================================\n");
		System.out.println("<#Index> <�����ñ�[C]> <�༺type> <�༺�̸�> <����ü> <ģ�е�> �����Դϴ�.");
		System.out.println("<����ü>: ���� �����ϴ��� �𸥴ٸ� ?�� ǥ�õ˴ϴ�.");
		System.out.println("          (����ü ���).(����ü�̸�)���� ǥ�õ˴ϴ�.");
		System.out.println("<ģ�е�>: ���� ����ü�� �������� �ʴ´ٸ� ?�� ǥ�õ˴ϴ�.\n\n");
		for (int i=0; i<PlanetList.size();i++)
		{
			System.out.print("#"+(i+1)+"   ");
			for (int j=0;j<5;j++)
				System.out.print(PlanetList.get(i)[j]+"    ");
			System.out.println("\n");
		}
		System.out.println("\n===============================================================================");
		System.out.println("ENTER�� �Է����ּ���.");
		Input();
	}
}
