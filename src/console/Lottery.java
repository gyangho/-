package console;


import java.util.ArrayList;
import java.util.Random;
import filecontrol.Fileread;

public class Lottery extends Fileread 
{
	 String findingName=null;
	 Random random = new Random();
	 String name;
	 int rate,sign;
	 ArrayList<String> listNumber = new ArrayList<String>();
	 
	 public Lottery(String file, String finding, int sign)
	 {
		 this.sign=sign;
		 fileName=file;
		 findingName=finding;
		 readFile();
		 seperate();
	 }
	 public Lottery() {}
	int random(int maxnum)
	 {
		return random.nextInt(maxnum);
	 }
	 void seperate()
	 {
		 int start=0;
		 for(int i=0;i<content.size();i++)
		 {
			 int idx= content.get(i).indexOf(" ");
			 if(idx==-1)
			 {
				 name=content.get(i);
				 rate=0;
			 }
			 else
			 {
			 name = content.get(i).substring(0 , idx);
			 String rStr = content.get(i).substring(idx);
			 rStr = rStr.trim();
			 rate = Integer.parseInt(rStr);
			 }
			 if(sign==0)
			 {
				 if(name.equals(findingName))
				 {
					 for(int j=0; j<rate; j++)
						 listNumber.add("Success");
					 break;
				 }
			 }
			 if(sign==1)
			 {
				 if(name.equals(findingName+"-end"))
					 break;
				 if(name.equals(findingName))
					 start++;
				 if(start==1)
					 for(int j=0 ; j<rate ; j++)
						 listNumber.add(name);
			 }
		 }
	 }
	String rand(int maxnum)
	 {
		 int ran = random.nextInt(maxnum);
		 if(listNumber.size() > maxnum)
		 {
			 System.out.println("확률이 "+maxnum+"을 넘을 수 없습니다." + ran);
			 System.out.println("메모장의 확률의 합을 확인해주세요.");
			 System.exit(0);
		 }
		 else
		 {
			 try 
			 {
				return listNumber.get(ran);
			 }
			 catch (IndexOutOfBoundsException ioe)
			 {
				 return "Fail";
			 }
		 }
		return "Error";
	}
}
