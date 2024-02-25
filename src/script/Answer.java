package script;

public class Answer implements Script 
{
	int num;
	public Answer(int i)
	{
		num=i;
	}
	@Override
	public void run() 
	{
		//====================================No====================================
		if(num==0)
		{
			String[] helpingScript= {"\n","아","우","렐","리","온"," ","솔",":"," ","\"","그","렇","게"," ","절","박","해","보","이","지"," ","않","는","군",".",".",".","\"","\n"};
			for(int i=0; i<helpingScript.length;i++)
			{
				System.out.print(helpingScript[i]);
				try 
				{
					Thread.sleep(100);
				}
				catch(InterruptedException e)
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
			
			String[] helpingScript2= {"              \n","\"","나","의"," ","신","성","한"," ","힘","은"," ","이","런"," ","곳","에"," ","쓰","는"," ","요","술"," ","따","위","가 ","아","니","다","!","\"","\n"};
			for(int i=0; i<helpingScript2.length;i++)
			{
				System.out.print(helpingScript2[i]);
				try 
				{
					Thread.sleep(100);
				}
				catch(InterruptedException e)
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
			
			String[] helpingScript3= {"\n","천","상","의"," ","용","은"," ","한","번"," ","내","려","다","보","고","는"," ","홀","연","히"," ","사","라","졌","다",".",".",".","\n"};
			for(int i=0; i<helpingScript3.length;i++)
			{
				System.out.print(helpingScript3[i]);
				try 
				{
					Thread.sleep(100);
				} 
				catch(InterruptedException e)
				{
					e.printStackTrace();
				}
			}
			try 
			{
				Thread.sleep(2000);
			} 
			catch(InterruptedException e)
			{
				e.printStackTrace();
			}
			System.out.println("\n친밀도가 \"2\"만큼 감소합니다.");
		}
		//====================================Drought====================================
		if(num==1)
		{			
			String[] helpingScript2= {"\n","천","상","의"," ","용","이"," ","입","김","을"," ","살","짝"," ","불","자"," ","원","소","들","이"," ","응","축","하","며"," ","비","구","름","이"," ","만","들","어","진","다",".","\n"};
			for(int i=0; i<helpingScript2.length;i++)
			{
				System.out.print(helpingScript2[i]);
				try 
				{
					Thread.sleep(100);
				}
				catch(InterruptedException e)
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
			
			String[] helpingScript3= {"\n","\"","비","가"," ","온","다","!","\"","고"," ","하","며"," ","생","명","체","들","이"," ","기","뻐","한","다",".","\n"};
			for(int i=0; i<helpingScript3.length;i++)
			{
				System.out.print(helpingScript3[i]);
				try 
				{
					Thread.sleep(100);
				} 
				catch(InterruptedException e)
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
			
			String[] helpingScript4= {"\n","아","우","렐","리","온"," ","솔"," : ","\"","이"," ","은","혜","를"," ","잊","지"," ","말","아","라",".",".",".","\"","\n"};
			for(int i=0; i<helpingScript4.length;i++)
			{
				System.out.print(helpingScript4[i]);
				try
				{
					Thread.sleep(100);
				} 
				catch(InterruptedException e)
				{
					e.printStackTrace();
				}
			}
			try
			{
				Thread.sleep(2000);
			} 
			catch(InterruptedException e)
			{
				e.printStackTrace();
			}
			System.out.println("\n친밀도가 \"2\"만큼 증가합니다.");
		}
		//====================================InnerWar====================================
		if(num==2)
		{
			String[] helpingScript= {"\n","천","상","의"," ","용","이"," ","입","을"," ","열","었","다",".","\n"};
			for(int i=0; i<helpingScript.length;i++)
			{
				System.out.print(helpingScript[i]);
				try 
				{
					Thread.sleep(100);
				}
				catch(InterruptedException e)
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
			String[] helpingScript2= {"\n","아","우","렐","리","온"," ","솔",":"," ","\"","내","가"," ","너","희","끼","리"," ","서","로"," ","죽","이","면","서"," ","이"," ","행","성","을"," ","파","괴","하","라","고"," ","이"," ","행","성","을"," ","만든 ","것 ","같","나","?","\"","\n"};
			for(int i=0; i<helpingScript2.length;i++)
			{
				System.out.print(helpingScript2[i]);
				try 
				{
					Thread.sleep(100);
				}
				catch(InterruptedException e)
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
			
			String[] helpingScript3= {"\n","\"","지","금"," ","당","장"," ","이"," ","전","쟁","을"," ","끝","내","지"," ","않","으","면"," ","내","가"," ","이"," ","행","성","을"," ","파","괴","하","겠","다",".","\"","\n"};
			for(int i=0; i<helpingScript3.length;i++)
			{
				System.out.print(helpingScript3[i]);
				try 
				{
					Thread.sleep(100);
				} 
				catch(InterruptedException e)
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
			
			String[] helpingScript4= {"\n","전","쟁","이"," ","멈","췄","고",","," ","생","명","체","들","은"," ","자","신","들","을"," ","지","키","려","는"," ","천","상","의"," ","용","의"," ","의","도","를"," ","알","아","차","리","는","데"," ","긴"," ","시","간","이"," ","걸","리","지"," ","않","았","다",".","\n"};
			for(int i=0; i<helpingScript4.length;i++)
			{
				System.out.print(helpingScript4[i]);
				try
				{
					Thread.sleep(100);
				} 
				catch(InterruptedException e)
				{
					e.printStackTrace();
				}
			}
			try
			{
				Thread.sleep(2000);
			} 
			catch(InterruptedException e)
			{
				e.printStackTrace();
			}
			System.out.println("\n친밀도가 \"2\"만큼 증가합니다.");
		}
		//====================================Emerge====================================
		if(num==3)
		{
			String[] helpingScript= {"\n","아","우","렐","리","온"," ","솔",":","\"","그","래","."," ","내","가"," ","천","상","의"," ","용","이","다","!","\"","\n"};
			for(int i=0; i<helpingScript.length;i++)
			{
				System.out.print(helpingScript[i]);
				try 
				{
					Thread.sleep(100);
				}
				catch(InterruptedException e)
				{
					e.printStackTrace();
				}	
			}
			try 
			{
				Thread.sleep(2000);
			} 
			catch(InterruptedException e)
			{
				e.printStackTrace();
			}
			System.out.println("\n친밀도가 \"6\"만큼 증가합니다.");
		}
		//====================================Plague====================================
		if(num==4)
		{
			String[] helpingScript= {"\n","아","우","렐","리","온"," ","솔",":"," ","\"","그","것"," ","또","한"," ","내","가"," ","만","들","어"," ","낸"," ","것","."," ","어","쩔 ","수 ","없","다",".",".",".","\"","\n"};
			for(int i=0; i<helpingScript.length;i++)
			{
				System.out.print(helpingScript[i]);
				try 
				{
					Thread.sleep(100);
				}
				catch(InterruptedException e)
				{
					e.printStackTrace();
				}	
			}
			try 
			{
				Thread.sleep(2000);
			} 
			catch(InterruptedException e)
			{
				e.printStackTrace();
			}
			System.out.println("\n친밀도가 \"6\"만큼 감소합니다.");
		}
		//====================================War====================================
		if(num==5||num==6)
		{
			String[] helpingScript= {"\n","천","상","의"," ","용","이"," ","기","를"," ","모","으","기"," ","시","작","한","다",".","\n"};
			for(int i=0; i<helpingScript.length;i++)
			{
				System.out.print(helpingScript[i]);
				try 
				{
					Thread.sleep(100);
				}
				catch(InterruptedException e)
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
			
			String[] helpingScript2= {"\n","곧","이","어"," ","그","의"," ","입"," ","주","변","에","서"," ","뜨","겁","게"," ","타","오","르","는"," ","구","가"," ","생","겨","났","다",".","\n"};
			for(int i=0; i<helpingScript2.length;i++)
			{
				System.out.print(helpingScript2[i]);
				try 
				{
					Thread.sleep(100);
				}
				catch(InterruptedException e)
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
			
			String[] helpingScript3= {"\n","천","상","의"," ","용","은"," ","그"," ","강","렬","한"," ","불","덩","이","를"," ","적","진","을"," ","향","해"," ","던","졌","다",".","\n"};
			for(int i=0; i<helpingScript3.length;i++)
			{
				System.out.print(helpingScript3[i]);
				try 
				{
					Thread.sleep(100);
				} 
				catch(InterruptedException e)
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
			
			String[] helpingScript4= {"\n","환","호","성","이"," ","들","린","다",".","\n"};
			for(int i=0; i<helpingScript4.length;i++)
			{
				System.out.print(helpingScript4[i]);
				try
				{
					Thread.sleep(100);
				} 
				catch(InterruptedException e)
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
			if(num==5)
			{
				String[] helpingScript5= {"\n","\"","우","리","가"," ","전","쟁","에","서"," ","승","리","했","다","!"," ","천","상","의"," ","용","이","시","여"," ","감","사","드","립","니","다","!","\"","\n"};
				for(int i=0; i<helpingScript5.length;i++)
				{
					System.out.print(helpingScript5[i]);
					try 
					{
						Thread.sleep(100);
					} 
					catch(InterruptedException e)
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
			}
			if(num==6)
			{
				String[] helpingScript6= {"\n","\"","방","어","에"," ","성","공","했","다","!"," ","천","상","의"," ","용","에","게"," ","감","사","의"," ","기","도","를"," ","드","려","라","!","\"","\n"};
				for(int i=0; i<helpingScript6.length;i++)
				{
					System.out.print(helpingScript6[i]);
					try 
					{
						Thread.sleep(100);
					} 
					catch(InterruptedException e)
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
			}
			String[] helpingScript7= {"\n","아","우","렐","리","온"," ","솔",":"," ","\"","나","의"," ","힘","을"," ","두","려","워","하","고"," ","숭","배","하","라",".",".",".","\"","\n"};
			for(int i=0; i<helpingScript7.length;i++)
			{
				System.out.print(helpingScript7[i]);
				try 
				{
					Thread.sleep(100);
				} 
				catch(InterruptedException e)
				{
					e.printStackTrace();
				}
			}
			try 
			{
				Thread.sleep(2000);
			} 
			catch(InterruptedException e)
			{
				e.printStackTrace();
			}	
		}
	}
}
