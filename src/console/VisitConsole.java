package console;

import script.Answer;
import script.Drought;
import script.Emerge;
import script.InnerWar;
import script.Plague;
import script.Visit;
import script.War;

public class VisitConsole extends Console
{
	private static int cnum=0;
	private static int[] count=new int[5];
	@Override
	public void firstscreen()
	{
		int num;
		clearConsole();
		System.out.print("\n\n\n\n");
		if (PlanetList.size()==0)
			System.out.println("                                        ���༺�� �������� �ʽ��ϴ�.��");
		for (int i=0; i<PlanetList.size();i++)
			System.out.println("\n                                        #"+(i+1)+" <"+PlanetList.get(i)[1]+">type <"+PlanetList.get(i)[2]+">");
		System.out.println("\n\n\n\n                                        �ٸ� Ű+Enter�� ������ ���θ޴��� �̵��մϴ�.");
		System.out.println("\n\n\n");
		System.out.println("�ƿ췼���� ��: ���� ������...\n");
		System.out.print("���ڸ� �Է����ּ��� >>");
		try 
		{
			num=Integer.parseInt(Input());
			clearConsole();
			Visit visit=new Visit();
			visit.run();
			System.out.println("===============================================================================\n");
			System.out.println("<"+PlanetList.get(num-1)[2]+">�༺�� �����߽��ϴ�.\n");
		} 
		catch(NumberFormatException e)
		{
			return;
		}
		catch(IndexOutOfBoundsException ioe)
		{
			return;
		}
		creature(num-1);
		System.out.println("\n�ð��� 1C��ŭ �������ϴ�.\n");
		Century++;
		System.out.println("===============================================================================");
		System.out.println("ENTER�� �Է����ּ���.");
		Input();
	}
	
	void creature(int i)
	{
		String[] PLstr=PlanetList.get(i);
		if((Century-Integer.parseInt(PLstr[0]))>=5 && PLstr[3].equals("?"))
		{
			Lottery Creature=new Lottery("./CreaturePercentage.txt",PLstr[1],1);
			String cname=Creature.rand(100);
			if(cname=="Fail")
			{
				System.out.println(PLstr[0]+"C �� ���� �� <"+PLstr[1]+">�� <"+PLstr[2]+"> �༺������ ����ü�� ���������ʽ��ϴ�..");
				PLstr[3]="X";
				PLstr[4]="X";
			}
			else
			{
				System.out.println(PLstr[0]+"C �� ���� �� <"+PLstr[1]+">�� <"+PLstr[2]+"> �༺���� ����ü <"+cname+">�� �����߽��ϴ�!");
				cnum++;
				PLstr[3]=cname;
				PLstr[4]="0";
				if(PLstr[1].equals("O"))
					PLstr[4]="30";
			}
		}
		else if(Character.isDigit(PLstr[3].charAt(0)))
			event(i);
	}
	
	void event(int i)
	{
		String[] Pl=PlanetList.get(i);
		Lottery random=new Lottery();
		int num=random.random(100);
		int target = 0;
		if(num/50==1)
		{
			System.out.println("����ü���� ��ȭ�Ӱ� �� ��ư��� �ִ�.");
		}
		else
		{
			if(num%20<7)
			{
				if(num%2==0)
				{
					num=1;
					switch(skip(num))
					{
					case 0:
						break;
					case 1:
						Pl[4]=Integer.toString(Integer.parseInt(Pl[4])+2);
						System.out.println("\n"+"<"+Pl[2]+">�༺���� "+"ģ�е��� \"2\"��ŭ �����մϴ�.");
						return;
					case 2:
						Pl[4]=Integer.toString(Integer.parseInt(Pl[4])-2);
						System.out.println("\n"+"<"+Pl[2]+">�༺���� "+"ģ�е��� \"2\"��ŭ �����մϴ�.");
						return;
					}
					Drought drought=new Drought();
					drought.run();
				}
				else
				{
					num=2;
					switch(skip(num))
					{
					case 0:
						break;
					case 1:
						Pl[4]=Integer.toString(Integer.parseInt(Pl[4])+2);
						System.out.println("\n"+"<"+Pl[2]+">�༺���� "+"ģ�е��� \"2\"��ŭ �����մϴ�.");
						return;
					case 2:
						Pl[4]=Integer.toString(Integer.parseInt(Pl[4])-2);
						System.out.println("\n"+"<"+Pl[2]+">�༺���� "+"ģ�е��� \"2\"��ŭ �����մϴ�.");
						return;
					}
					InnerWar innerwar=new InnerWar();
					innerwar.run();
				}
			}
			else if(num%20<13)
			{
				if(num%2==0)
				{
					num=3;
					switch(skip(num))
					{
					case 0:
						break;
					case 1:
						Pl[4]=Integer.toString(Integer.parseInt(Pl[4])+6);
						System.out.println("\n"+"<"+Pl[2]+">�༺���� "+"ģ�е��� \"6\"��ŭ �����մϴ�.");
						return;
					}
					Emerge emerge=new Emerge();
					emerge.run();
				}
				else
				{
					num=4;
					switch(skip(num))
					{
					case 0:
						break;
					case 1:
						Pl[4]=Integer.toString(Integer.parseInt(Pl[4])-6);
						System.out.println("\n"+"<"+Pl[2]+">�༺���� "+"ģ�е��� \"6\"��ŭ �����մϴ�.");
						return;
					}
					Plague plague=new Plague();
					plague.run();
				}
			}
			else
			{
				if(cnum<2)
				{
					System.out.println("����ü���� ��ȭ�Ӱ� �� ��ư��� �ִ�.");
					return;
				}
				do
				{
					target=num%PlanetList.size();
				}while(target!=i);
				num=5;
				switch(skip(num))
				{
				case 0:
					break;
				case 1:
					Pl[4]=Integer.toString(Integer.parseInt(Pl[4])+8);
					PlanetList.get(target)[4]=Integer.toString(Integer.parseInt(PlanetList.get(target)[4])-8);
					System.out.println("\n"+"<"+Pl[2]+">�༺���� "+"ģ�е��� \"8\"��ŭ �����մϴ�.");
					System.out.println("\n"+"<"+PlanetList.get(target)[2]+">�༺���� "+"ģ�е��� \"8\"��ŭ �����մϴ�.");
					return;
				case 2:
					PlanetList.get(target)[4]=Integer.toString(Integer.parseInt(PlanetList.get(target)[4])+8);
					Pl[4]=Integer.toString(Integer.parseInt(Pl[4])-8);
					System.out.println("\n"+"<"+Pl[2]+">�༺���� "+"ģ�е��� \"8\"��ŭ �����մϴ�.");
					System.out.println("\n"+"<"+PlanetList.get(target)[2]+">�༺���� "+"ģ�е��� \"8\"��ŭ �����մϴ�.");
					return;
				}
				War war=new War(Pl[2],PlanetList.get(target)[2]);
				war.run();
			}
			while(true)
			{
				int frd2=0;
				if (num==5)
					frd2=Integer.parseInt(PlanetList.get(target)[4]);
				int frd=Integer.parseInt(Pl[4]);
				String answ=Input();
				if(num==3 || num==4)
				{
					switch(num)
					{
					case 3:
						frd+=6;
						break;
					case 4:
						frd-=6;
						break;
					}
				}
				else if(answ.equals("Y")||answ.equals("y"))
				{
					switch(num)
					{
					case 1:case 2:
						frd+=2;
						break;
					case 5:
						frd+=8;
						frd2-=8;
						break;
					}
				}
				else if(answ.equals("N")||answ.equals("n"))
				{
					switch(num)
					{
					case 1:case 2:
						frd-=2;
						break;
					case 5:
						frd-=8;
						frd2-=8;
						break;
					}
					if(num==5)
						num++;
					if(num==1 || num==2)
						num=0;
				}
				else
					continue;
				Answer answer=new Answer(num);
				answer.run();
				Pl[4]=Integer.toString(frd);
				if(num==5)
				{

					PlanetList.get(target)[4]=Integer.toString(frd2);
					System.out.println("\n"+"<"+Pl[2]+">�༺���� "+"ģ�е��� \"8\"��ŭ �����մϴ�.");
					System.out.println("\n"+"<"+PlanetList.get(target)[2]+">�༺���� "+"ģ�е��� \"8\"��ŭ �����մϴ�.");
				}
				if(num==6)
				{
					PlanetList.get(target)[4]=Integer.toString(frd2);
					System.out.println("\n"+"<"+Pl[2]+">�༺���� "+"ģ�е��� \"8\"��ŭ �����մϴ�.");
					System.out.println("\n"+"<"+PlanetList.get(target)[2]+">�༺���� "+"ģ�е��� \"8\"��ŭ �����մϴ�.");
				}
				break;
			}
		}
	}
	
	int skip(int num)
	{
		String[] event= {"����","����","����","������","����"};
		String skip;
		if(count[num-1]>0)
		{
			System.out.print("\""+event[num-1]+"\" �̺�Ʈ�� �߻��߽��ϴ�. ��ŵ�ұ��? (Y/N)>> ");
			while(true)
			{
				skip=Input();
				if(skip.equals("Y")||skip.equals("y"))
				{
					if(num<3||num>4)
					{
						System.out.print("�̺�Ʈ ���򿩺θ� ����ּ���(Y/N)>> ");
						skip=Input();
						if(skip.equals("Y")||skip.equals("y"))
							return 1;
						else if(skip.equals("N")||skip.equals("n"))
							return 2;
					}
					else
						return 1;
				}
				else if(skip.equals("N")||skip.equals("n"))
					break;
			}
		}
		count[num-1]++;
		return 0;
	}
}

