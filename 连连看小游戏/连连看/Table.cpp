// Table.cpp: implementation of the Table class.


#include "StdAfx.h"
#include "Table.h"

//消除模块时的音效 多线程*********************************************************************************
void Thread1()
{
	//播放消除音效*******
	mciSendString("open 1.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//延迟***
				// 停止播放并关闭音乐*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//销毁线程***********
	ExitThread(0);

}
void Thread2()
{
	//播放消除音效*******
	mciSendString("open 2.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//延迟***
				// 停止播放并关闭音乐*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//销毁线程***********
	ExitThread(0);

}
void Thread3()
{
	//播放消除音效*******
	mciSendString("open 3.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//延迟***
				// 停止播放并关闭音乐*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//销毁线程***********
	ExitThread(0);

}
void Thread4()
{
	//播放消除音效*******
	mciSendString("open 4.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//延迟***
				// 停止播放并关闭音乐*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//销毁线程***********
	ExitThread(0);

}
void Thread5()
{
	//播放消除音效*******
	mciSendString("open 5.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//延迟***
				// 停止播放并关闭音乐*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//销毁线程***********
	ExitThread(0);

}
void Thread6()
{
	//播放消除音效*******
	mciSendString("open 6.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//延迟***
				// 停止播放并关闭音乐*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//销毁线程***********
	ExitThread(0);

}
void Thread7()
{
	//播放消除音效*******
	mciSendString("open 7.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//延迟***
				// 停止播放并关闭音乐*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//销毁线程***********
	ExitThread(0);

}
void Thread8()
{
	//播放消除音效*******
	mciSendString("open 8.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//延迟***
				// 停止播放并关闭音乐*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//销毁线程***********
	ExitThread(0);

}
void Thread9()
{
	//播放消除音效*******
	mciSendString("open 9.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//延迟***
				// 停止播放并关闭音乐*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//销毁线程***********
	ExitThread(0);

}
void Thread10()
{
	//播放消除音效*******
	mciSendString("open 10.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//延迟***
				// 停止播放并关闭音乐*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//销毁线程***********
	ExitThread(0);

}
void Thread11()
{
	//播放消除音效*******
	mciSendString("open 11.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//延迟***
				// 停止播放并关闭音乐*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//销毁线程***********
	ExitThread(0);

}

Table::Table()//初始化
{
	memset(tableArrary ,0 , sizeof(tableArrary));
	first_click.choice=0;
	first_click.type=-1;
	first_click.x=0;
	first_click.y=0;
	second_click.choice=0;
	second_click.type=-1;
	second_click.x=0;
	second_click.y=0;
	srand((int)time(NULL));
}

void Table::Table_Set_count(int n)//设置图片方格数量
{
	count=n;
}

int Table::Table_Get_count()//获得图片方格数量
{
	return count;
}

bool Table::X_through(int y,int x1,int x2)//看是否可以与另一个元素的延伸线进行水平连线
{
	int n=0;
	if(x1>x2)
	{
		n=x1;
		x1=x2;
		x2=n;
	}
	if(x1+1==x2)
		return 1;
	for(int i=x1+1;i<x2;i++)
	{
		if(tableArrary[y][i].type<0)
		{

		}
		else
		{
			return 0;
		}
	}
	return 1;	
}

bool Table::Y_through(int x,int y1,int y2)//看是否可以与另一个元素的延伸线进行垂直连线
{
	int n=0;
	if(y1>y2)
	{
		n=y2;
		y2=y1;
		y1=n;
	}
	if(y1+1==y2)
		return 1;
	for(int i=y1+1;i<y2;i++)
	{
		if(tableArrary[i][x].type<0)
		{

		}
		else
		{
			return 0;
		}		
	}
	return 1;
}

void Table::Set_Size(int width,int height)//设置每一个方格的大小
{
	first_click.x=first_click.x*ClientWidth/width;
	first_click.y=first_click.y*ClientHeight/height;

	second_click.x=second_click.x*ClientWidth/width;
	second_click.y=second_click.y*ClientHeight/height;


	ClientWidth=width/10;
	ClientHeight=height/8;

	for(int m=0;m<A_HEIGHT+2;m++)
	{
		for(int n=0;n<A_WEITH+2;n++)
		{
			tableArrary[m][n].x=n*ClientWidth;
			tableArrary[m][n].y=m*ClientHeight;
		}
	}
	for(int i=0;i<A_HEIGHT;i++)
	{
		for(int j=0;j<A_WEITH;j++)
		{
			tableArrary[i+1][j+1].x=(j+1)*ClientWidth;
			tableArrary[i+1][j+1].y=(i+1)*ClientHeight;
		}
	}
}

int Table::Get_Height()//获得游戏画面高度
{
	return ClientHeight;
}

int Table::Get_Width()//获得游戏画面宽度
{
	return ClientWidth;
}


bool Table::InitTable()//初始化游戏的图片方格
{

	PLIST Initlink;
	Initlink = (PLIST)malloc(sizeof(LIST));
	LinkList(Initlink);
	for(int k=0;k<40;k++)
	{
		Insert(Initlink,(int)rand()%34+1);
	
	}
	for(int m=0;m<A_HEIGHT+2;m++)
	{
		for(int n=0;n<A_WEITH+2;n++)
		{
			tableArrary[m][n].choice=0;
			tableArrary[m][n].x=n*ClientWidth;
			tableArrary[m][n].y=m*ClientHeight;
			tableArrary[m][n].type=-1;
		}
	}
	for(int i=0;i<A_HEIGHT;i++)
	{
		for(int j=0;j<A_WEITH;j++)
		{
			tableArrary[i+1][j+1].choice=0;
			tableArrary[i+1][j+1].x=(j+1)*ClientWidth;
			tableArrary[i+1][j+1].y=(i+1)*ClientHeight;
			tableArrary[i + 1][j + 1].type = Delete(Initlink,rand() % (GetCount(Initlink)));//随机得到图片类型

		}
	}
	this->count=80;
	return true;
}

void Table::Set_first_click(int x,int y)//第一次点击
{
	tableArrary[y][x].choice=1;
	first_click.choice=tableArrary[y][x].choice;
	first_click.type=tableArrary[y][x].type;
	first_click.x=(tableArrary[y][x].x)/ClientWidth;
	first_click.y=(tableArrary[y][x].y)/ClientHeight;
}

void Table::Set_second_click(int x,int y)//第二次点击
{
	tableArrary[y][x].choice=1;
	second_click.choice=tableArrary[y][x].choice;
	second_click.type=tableArrary[y][x].type;
	second_click.x=(tableArrary[y][x].x)/ClientWidth;
	second_click.y=(tableArrary[y][x].y)/ClientHeight;

}


void Table::Delete_first_click(int x,int y)//删除第一次点击
{
	tableArrary[y][x].choice=0;
	first_click.choice=0;
	first_click.type=0;
	first_click.x=0;
	first_click.y=0;
}

void Table::Delete_second_click(int x,int y)//删除第二次点击
{
	tableArrary[y][x].choice=0;
	second_click.choice=0;
	second_click.type=0;
	second_click.x=0;
	second_click.y=0;
}

PicturePoint  Table::Get_first_click()//获得第一次点击
{
	return first_click;
}

PicturePoint  Table::Get_second_click()//获得第二次点击
{
	return second_click;
}

bool Table::Two_Link()//判断两次点击选择图片能否相连
{
	int fx=first_click.x;
	int fy=first_click.y;
	int sx=second_click.x;
	int sy=second_click.y;
	int midle=0;
	int line_x=0;
	int line_y=0;

	
	if(first_click.type==second_click.type)//如果两张图片相同
	{		
		if(fx<sx) //    first 在 scend  左边 
		{
			if(fy==sy)  //    first 在 scend  在正左边	//ok
			{
				if(X_through(fy,fx,sx))//  成立 
				{
					//创建新线程，消除音效*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//第二线程执行Thread1函数***************************
					hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread1, NULL, 0, &ThreadID);
					return 1;
				}
				//////////////////////
				line_y=0;
				while(line_y<=9)
				{
					if(X_through(line_y,fx,sx)&&Y_through(sx,sy,line_y)&&Y_through(fx,fy,line_y)&&
						(tableArrary[line_y][fx].type<0)&&(tableArrary[line_y][sx].type<0))
					{
						line_y=0;
						//创建新线程，消除音效*****************************
						HANDLE hThread;
						DWORD ThreadID;
						//第二线程执行Thread1函数***************************
						hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread2, NULL, 0, &ThreadID);
						return 1;
					}
					line_y++;
				}
				line_y=0;
				//////////////////////

				return 0;
			}
			else if(fy>sy)	//    first 在 scend  在左下方  //OK
			{
				line_y=0;
				while(line_y<=9)
				{
					if(X_through(line_y,fx,sx)&&Y_through(sx,sy,line_y)&&Y_through(fx,fy,line_y)&&
						(tableArrary[line_y][fx].type<0)&&(tableArrary[line_y][sx].type<0))
					{
						line_y=0;
						//创建新线程，消除音效*****************************
						HANDLE hThread;
						DWORD ThreadID;
						//第二线程执行Thread1函数***************************
						hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread3, NULL, 0, &ThreadID);
						return 1;
					}
					line_y++;
				}
				line_y=0;

				line_x=0;
				while(line_x<=11)
				{
					if(Y_through(line_x,sy,fy)&&X_through(sy,line_x,sx)&&X_through(fy,line_x,fx)&&
						(tableArrary[sy][line_x].type<0)&&(tableArrary[fy][line_x].type<0)) 
					{
						line_x=0;
						//创建新线程，消除音效*****************************
						HANDLE hThread;
						DWORD ThreadID;
						//第二线程执行Thread1函数***************************
						hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread4, NULL, 0, &ThreadID);
						return 1;
					}
					line_x++;
				}
				line_x=0;

				if(X_through(fy,fx,sx)&&Y_through(sx,sy,fy)&&(tableArrary[fy][sx].type<0))
				{
					//创建新线程，消除音效*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//第二线程执行Thread1函数***************************
					hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread5, NULL, 0, &ThreadID);
					return 1;
				}
				if(X_through(sy,fx,sx)&&Y_through(fx,sy,fy)&&(tableArrary[sy][fx].type<0)) 
				{
					//创建新线程，消除音效*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//第二线程执行Thread1函数***************************
					hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread6, NULL, 0, &ThreadID);
					return 1;
				}
				return 0;	
			}		
			else  		//    first 在 scend  在左上方   //OK
			{
				///////////////////////
				line_y=0;
				while(line_y<=9)
				{
					if(X_through(line_y,fx,sx)&&Y_through(sx,sy,line_y)&&Y_through(fx,fy,line_y)&&
						(tableArrary[line_y][fx].type<0)&&(tableArrary[line_y][sx].type<0))
					{
						line_y=0;
						//创建新线程，消除音效*****************************
						HANDLE hThread;
						DWORD ThreadID;
						//第二线程执行Thread1函数***************************
						hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread7, NULL, 0, &ThreadID);
						return 1;
					}
					line_y++;
				}
				line_y=0;

				line_x=0;
				while(line_x<=11)
				{
					if(Y_through(line_x,sy,fy)&&X_through(sy,line_x,sx)&&X_through(fy,line_x,fx)&&
						(tableArrary[sy][line_x].type<0)&&(tableArrary[fy][line_x].type<0)) 
					{
						line_x=0;
						//创建新线程，消除音效*****************************
						HANDLE hThread;
						DWORD ThreadID;
						//第二线程执行Thread1函数***************************
						hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread7, NULL, 0, &ThreadID);
						return 1;
					}
					line_x++;
				}
				line_x=0;
				///////////////////
				if(X_through(sy,fx,sx)&&Y_through(fx,fy,sy)&&(tableArrary[sy][fx].type<0))
				{
					//创建新线程，消除音效*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//第二线程执行Thread1函数***************************
					hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread8, NULL, 0, &ThreadID);
					return 1;
				}
				if(X_through(fy,fx,sx)&&Y_through(sx,fy,sy)&&(tableArrary[fy][sx].type<0)) 
				{
					//创建新线程，消除音效*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//第二线程执行Thread1函数***************************
					hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread9, NULL, 0, &ThreadID);
					return 1;
				}
				else
				{
					return 0;
				}
				
			}
		}
		else if(fx>sx)   //    first 在 scend  右边 
		{
			if(fy==sy)		//    first 在 scend  在正右边    //OK
			{

				if(X_through(fy,sx,fx))//  成立 
				{
					//创建新线程，消除音效*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//第二线程执行Thread1函数***************************
					hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread10, NULL, 0, &ThreadID);
					return 1;
				}
				//////////////////////
				line_y=0;
				while(line_y<=9)
				{
					if(X_through(line_y,fx,sx)&&Y_through(sx,sy,line_y)&&Y_through(fx,fy,line_y)&&
						(tableArrary[line_y][fx].type<0)&&(tableArrary[line_y][sx].type<0))
					{
						line_y=0;
						//创建新线程，消除音效*****************************
						HANDLE hThread;
						DWORD ThreadID;
						//第二线程执行Thread1函数***************************
						hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread11, NULL, 0, &ThreadID);
						return 1;
					}
					line_y++;
				}
				line_y=0;
				//////////////////////
	
				return 0;
			}
			else if(fy>sy)	//    first 在 scend  在右下方   //OK
			{
				////////////////
				line_y=0;
				while(line_y<=9)
				{
					if(X_through(line_y,fx,sx)&&Y_through(sx,sy,line_y)&&Y_through(fx,fy,line_y)&&
						(tableArrary[line_y][fx].type<0)&&(tableArrary[line_y][sx].type<0))
					{
						line_y=0;
						//创建新线程，消除音效*****************************
						HANDLE hThread;
						DWORD ThreadID;
						//第二线程执行Thread1函数***************************
						hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread11, NULL, 0, &ThreadID);
						return 1;
					}
					line_y++;
				}
				line_y=0;

				line_x=0;
				while(line_x<=11)
				{
					if(Y_through(line_x,sy,fy)&&X_through(sy,line_x,sx)&&X_through(fy,line_x,fx)&&
						(tableArrary[sy][line_x].type<0)&&(tableArrary[fy][line_x].type<0)) 
					{
						line_x=0;
						//创建新线程，消除音效*****************************
						HANDLE hThread;
						DWORD ThreadID;
						//第二线程执行Thread1函数***************************
						hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread1, NULL, 0, &ThreadID);
						return 1;
					}
					line_x++;
				}
				line_x=0;
				/////////////////
				if(X_through(sy,sx,fx)&&Y_through(fx,sy,fy)&&(tableArrary[sy][fx].type<0))
				{
					//创建新线程，消除音效*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//第二线程执行Thread1函数***************************
					hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread10, NULL, 0, &ThreadID);
					return 1;
				}
				else if(X_through(fy,sx,fx)&&Y_through(sx,sy,fy)&&(tableArrary[fy][sx].type<0)) 
				{
					return 1;
				}
				else
				{
					return 0;
				}	
			}
			else			//    first 在 scend  在右上方  //OK
			{
				////////////////
				line_y=0;
				while(line_y<=9)
				{
					if(X_through(line_y,fx,sx)&&Y_through(sx,sy,line_y)&&Y_through(fx,fy,line_y)&&
						(tableArrary[line_y][fx].type<0)&&(tableArrary[line_y][sx].type<0))
					{
						line_y=0;
						//创建新线程，消除音效*****************************
						HANDLE hThread;
						DWORD ThreadID;
						//第二线程执行Thread1函数***************************
						hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread1, NULL, 0, &ThreadID);
						return 1;
					}
					line_y++;
				}
				line_y=0;

				line_x=0;
				while(line_x<=11)
				{
					if(Y_through(line_x,sy,fy)&&X_through(sy,line_x,sx)&&X_through(fy,line_x,fx)&&
						(tableArrary[sy][line_x].type<0)&&(tableArrary[fy][line_x].type<0)) 
					{
						line_x=0;
						return 1;
					}
					line_x++;
				}
				line_x=0;
				/////////////////

				if(X_through(sy,sx,fx)&&Y_through(fx,fy,sy)&&(tableArrary[sy][fx].type<0))
				{
					//创建新线程，消除音效*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//第二线程执行Thread1函数***************************
					hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread1, NULL, 0, &ThreadID);
					return 1;
				}
				else if(X_through(fy,sx,fx)&&Y_through(sx,fy,sy)&&(tableArrary[fy][sx].type<0)) 
				{
					//创建新线程，消除音效*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//第二线程执行Thread1函数***************************
					hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread1, NULL, 0, &ThreadID);
					return 1;
				}
				else
				{
					return 0;
				}	
			}
		}
		else	if(fx==sx)			//    first 在 scend  在同 X  上 
		{
			if(fy>sy)
			{

				if(Y_through(fx,sy,fy))//  正下方
				{
					//创建新线程，消除音效*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//第二线程执行Thread1函数***************************
					hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread1, NULL, 0, &ThreadID);
					return 1;
				}
				////////////////
				line_x=0;
				while(line_x<=11)
				{
					if(Y_through(line_x,sy,fy)&&X_through(sy,line_x,sx)&&X_through(fy,line_x,fx)&&
						(tableArrary[sy][line_x].type<0)&&(tableArrary[fy][line_x].type<0)) 
					{
						line_x=0;
						//创建新线程，消除音效*****************************
						HANDLE hThread;
						DWORD ThreadID;
						//第二线程执行Thread1函数***************************
						hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread1, NULL, 0, &ThreadID);
						return 1;
					}
					line_x++;
				}
				line_x=0;
				/////////////////
				return 0;
			}
			else if(fy<sy)
			{

				if(Y_through(fx,fy,sy))//  正上方
				{
					//创建新线程，消除音效*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//第二线程执行Thread1函数***************************
					hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread1, NULL, 0, &ThreadID);
					return 1;
				}
				////////////////
				line_x=0;
				while(line_x<=11)
				{
					if(Y_through(line_x,sy,fy)&&X_through(sy,line_x,sx)&&X_through(fy,line_x,fx)&&
						(tableArrary[sy][line_x].type<0)&&(tableArrary[fy][line_x].type<0)) 
					{
						line_x=0;
						return 1;
					}
					line_x++;
				}
				line_x=0;
				/////////////////
				return 0;
			}
			else
			{

			}
		}
	}	
	else
		return 0;
}

bool Table::Is_Linked()//判断两次点击是否相连
{
	return Two_Link();	
}










