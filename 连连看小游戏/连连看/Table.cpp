// Table.cpp: implementation of the Table class.


#include "StdAfx.h"
#include "Table.h"

//����ģ��ʱ����Ч ���߳�*********************************************************************************
void Thread1()
{
	//����������Ч*******
	mciSendString("open 1.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//�ӳ�***
				// ֹͣ���Ų��ر�����*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//�����߳�***********
	ExitThread(0);

}
void Thread2()
{
	//����������Ч*******
	mciSendString("open 2.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//�ӳ�***
				// ֹͣ���Ų��ر�����*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//�����߳�***********
	ExitThread(0);

}
void Thread3()
{
	//����������Ч*******
	mciSendString("open 3.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//�ӳ�***
				// ֹͣ���Ų��ر�����*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//�����߳�***********
	ExitThread(0);

}
void Thread4()
{
	//����������Ч*******
	mciSendString("open 4.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//�ӳ�***
				// ֹͣ���Ų��ر�����*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//�����߳�***********
	ExitThread(0);

}
void Thread5()
{
	//����������Ч*******
	mciSendString("open 5.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//�ӳ�***
				// ֹͣ���Ų��ر�����*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//�����߳�***********
	ExitThread(0);

}
void Thread6()
{
	//����������Ч*******
	mciSendString("open 6.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//�ӳ�***
				// ֹͣ���Ų��ر�����*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//�����߳�***********
	ExitThread(0);

}
void Thread7()
{
	//����������Ч*******
	mciSendString("open 7.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//�ӳ�***
				// ֹͣ���Ų��ر�����*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//�����߳�***********
	ExitThread(0);

}
void Thread8()
{
	//����������Ч*******
	mciSendString("open 8.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//�ӳ�***
				// ֹͣ���Ų��ر�����*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//�����߳�***********
	ExitThread(0);

}
void Thread9()
{
	//����������Ч*******
	mciSendString("open 9.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//�ӳ�***
				// ֹͣ���Ų��ر�����*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//�����߳�***********
	ExitThread(0);

}
void Thread10()
{
	//����������Ч*******
	mciSendString("open 10.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//�ӳ�***
				// ֹͣ���Ų��ر�����*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//�����߳�***********
	ExitThread(0);

}
void Thread11()
{
	//����������Ч*******
	mciSendString("open 11.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
	Sleep(2100);//�ӳ�***
				// ֹͣ���Ų��ر�����*
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	//�����߳�***********
	ExitThread(0);

}

Table::Table()//��ʼ��
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

void Table::Table_Set_count(int n)//����ͼƬ��������
{
	count=n;
}

int Table::Table_Get_count()//���ͼƬ��������
{
	return count;
}

bool Table::X_through(int y,int x1,int x2)//���Ƿ��������һ��Ԫ�ص������߽���ˮƽ����
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

bool Table::Y_through(int x,int y1,int y2)//���Ƿ��������һ��Ԫ�ص������߽��д�ֱ����
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

void Table::Set_Size(int width,int height)//����ÿһ������Ĵ�С
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

int Table::Get_Height()//�����Ϸ����߶�
{
	return ClientHeight;
}

int Table::Get_Width()//�����Ϸ������
{
	return ClientWidth;
}


bool Table::InitTable()//��ʼ����Ϸ��ͼƬ����
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
			tableArrary[i + 1][j + 1].type = Delete(Initlink,rand() % (GetCount(Initlink)));//����õ�ͼƬ����

		}
	}
	this->count=80;
	return true;
}

void Table::Set_first_click(int x,int y)//��һ�ε��
{
	tableArrary[y][x].choice=1;
	first_click.choice=tableArrary[y][x].choice;
	first_click.type=tableArrary[y][x].type;
	first_click.x=(tableArrary[y][x].x)/ClientWidth;
	first_click.y=(tableArrary[y][x].y)/ClientHeight;
}

void Table::Set_second_click(int x,int y)//�ڶ��ε��
{
	tableArrary[y][x].choice=1;
	second_click.choice=tableArrary[y][x].choice;
	second_click.type=tableArrary[y][x].type;
	second_click.x=(tableArrary[y][x].x)/ClientWidth;
	second_click.y=(tableArrary[y][x].y)/ClientHeight;

}


void Table::Delete_first_click(int x,int y)//ɾ����һ�ε��
{
	tableArrary[y][x].choice=0;
	first_click.choice=0;
	first_click.type=0;
	first_click.x=0;
	first_click.y=0;
}

void Table::Delete_second_click(int x,int y)//ɾ���ڶ��ε��
{
	tableArrary[y][x].choice=0;
	second_click.choice=0;
	second_click.type=0;
	second_click.x=0;
	second_click.y=0;
}

PicturePoint  Table::Get_first_click()//��õ�һ�ε��
{
	return first_click;
}

PicturePoint  Table::Get_second_click()//��õڶ��ε��
{
	return second_click;
}

bool Table::Two_Link()//�ж����ε��ѡ��ͼƬ�ܷ�����
{
	int fx=first_click.x;
	int fy=first_click.y;
	int sx=second_click.x;
	int sy=second_click.y;
	int midle=0;
	int line_x=0;
	int line_y=0;

	
	if(first_click.type==second_click.type)//�������ͼƬ��ͬ
	{		
		if(fx<sx) //    first �� scend  ��� 
		{
			if(fy==sy)  //    first �� scend  �������	//ok
			{
				if(X_through(fy,fx,sx))//  ���� 
				{
					//�������̣߳�������Ч*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//�ڶ��߳�ִ��Thread1����***************************
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
						//�������̣߳�������Ч*****************************
						HANDLE hThread;
						DWORD ThreadID;
						//�ڶ��߳�ִ��Thread1����***************************
						hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread2, NULL, 0, &ThreadID);
						return 1;
					}
					line_y++;
				}
				line_y=0;
				//////////////////////

				return 0;
			}
			else if(fy>sy)	//    first �� scend  �����·�  //OK
			{
				line_y=0;
				while(line_y<=9)
				{
					if(X_through(line_y,fx,sx)&&Y_through(sx,sy,line_y)&&Y_through(fx,fy,line_y)&&
						(tableArrary[line_y][fx].type<0)&&(tableArrary[line_y][sx].type<0))
					{
						line_y=0;
						//�������̣߳�������Ч*****************************
						HANDLE hThread;
						DWORD ThreadID;
						//�ڶ��߳�ִ��Thread1����***************************
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
						//�������̣߳�������Ч*****************************
						HANDLE hThread;
						DWORD ThreadID;
						//�ڶ��߳�ִ��Thread1����***************************
						hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread4, NULL, 0, &ThreadID);
						return 1;
					}
					line_x++;
				}
				line_x=0;

				if(X_through(fy,fx,sx)&&Y_through(sx,sy,fy)&&(tableArrary[fy][sx].type<0))
				{
					//�������̣߳�������Ч*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//�ڶ��߳�ִ��Thread1����***************************
					hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread5, NULL, 0, &ThreadID);
					return 1;
				}
				if(X_through(sy,fx,sx)&&Y_through(fx,sy,fy)&&(tableArrary[sy][fx].type<0)) 
				{
					//�������̣߳�������Ч*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//�ڶ��߳�ִ��Thread1����***************************
					hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread6, NULL, 0, &ThreadID);
					return 1;
				}
				return 0;	
			}		
			else  		//    first �� scend  �����Ϸ�   //OK
			{
				///////////////////////
				line_y=0;
				while(line_y<=9)
				{
					if(X_through(line_y,fx,sx)&&Y_through(sx,sy,line_y)&&Y_through(fx,fy,line_y)&&
						(tableArrary[line_y][fx].type<0)&&(tableArrary[line_y][sx].type<0))
					{
						line_y=0;
						//�������̣߳�������Ч*****************************
						HANDLE hThread;
						DWORD ThreadID;
						//�ڶ��߳�ִ��Thread1����***************************
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
						//�������̣߳�������Ч*****************************
						HANDLE hThread;
						DWORD ThreadID;
						//�ڶ��߳�ִ��Thread1����***************************
						hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread7, NULL, 0, &ThreadID);
						return 1;
					}
					line_x++;
				}
				line_x=0;
				///////////////////
				if(X_through(sy,fx,sx)&&Y_through(fx,fy,sy)&&(tableArrary[sy][fx].type<0))
				{
					//�������̣߳�������Ч*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//�ڶ��߳�ִ��Thread1����***************************
					hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread8, NULL, 0, &ThreadID);
					return 1;
				}
				if(X_through(fy,fx,sx)&&Y_through(sx,fy,sy)&&(tableArrary[fy][sx].type<0)) 
				{
					//�������̣߳�������Ч*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//�ڶ��߳�ִ��Thread1����***************************
					hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread9, NULL, 0, &ThreadID);
					return 1;
				}
				else
				{
					return 0;
				}
				
			}
		}
		else if(fx>sx)   //    first �� scend  �ұ� 
		{
			if(fy==sy)		//    first �� scend  �����ұ�    //OK
			{

				if(X_through(fy,sx,fx))//  ���� 
				{
					//�������̣߳�������Ч*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//�ڶ��߳�ִ��Thread1����***************************
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
						//�������̣߳�������Ч*****************************
						HANDLE hThread;
						DWORD ThreadID;
						//�ڶ��߳�ִ��Thread1����***************************
						hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread11, NULL, 0, &ThreadID);
						return 1;
					}
					line_y++;
				}
				line_y=0;
				//////////////////////
	
				return 0;
			}
			else if(fy>sy)	//    first �� scend  �����·�   //OK
			{
				////////////////
				line_y=0;
				while(line_y<=9)
				{
					if(X_through(line_y,fx,sx)&&Y_through(sx,sy,line_y)&&Y_through(fx,fy,line_y)&&
						(tableArrary[line_y][fx].type<0)&&(tableArrary[line_y][sx].type<0))
					{
						line_y=0;
						//�������̣߳�������Ч*****************************
						HANDLE hThread;
						DWORD ThreadID;
						//�ڶ��߳�ִ��Thread1����***************************
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
						//�������̣߳�������Ч*****************************
						HANDLE hThread;
						DWORD ThreadID;
						//�ڶ��߳�ִ��Thread1����***************************
						hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread1, NULL, 0, &ThreadID);
						return 1;
					}
					line_x++;
				}
				line_x=0;
				/////////////////
				if(X_through(sy,sx,fx)&&Y_through(fx,sy,fy)&&(tableArrary[sy][fx].type<0))
				{
					//�������̣߳�������Ч*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//�ڶ��߳�ִ��Thread1����***************************
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
			else			//    first �� scend  �����Ϸ�  //OK
			{
				////////////////
				line_y=0;
				while(line_y<=9)
				{
					if(X_through(line_y,fx,sx)&&Y_through(sx,sy,line_y)&&Y_through(fx,fy,line_y)&&
						(tableArrary[line_y][fx].type<0)&&(tableArrary[line_y][sx].type<0))
					{
						line_y=0;
						//�������̣߳�������Ч*****************************
						HANDLE hThread;
						DWORD ThreadID;
						//�ڶ��߳�ִ��Thread1����***************************
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
					//�������̣߳�������Ч*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//�ڶ��߳�ִ��Thread1����***************************
					hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread1, NULL, 0, &ThreadID);
					return 1;
				}
				else if(X_through(fy,sx,fx)&&Y_through(sx,fy,sy)&&(tableArrary[fy][sx].type<0)) 
				{
					//�������̣߳�������Ч*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//�ڶ��߳�ִ��Thread1����***************************
					hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread1, NULL, 0, &ThreadID);
					return 1;
				}
				else
				{
					return 0;
				}	
			}
		}
		else	if(fx==sx)			//    first �� scend  ��ͬ X  �� 
		{
			if(fy>sy)
			{

				if(Y_through(fx,sy,fy))//  ���·�
				{
					//�������̣߳�������Ч*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//�ڶ��߳�ִ��Thread1����***************************
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
						//�������̣߳�������Ч*****************************
						HANDLE hThread;
						DWORD ThreadID;
						//�ڶ��߳�ִ��Thread1����***************************
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

				if(Y_through(fx,fy,sy))//  ���Ϸ�
				{
					//�������̣߳�������Ч*****************************
					HANDLE hThread;
					DWORD ThreadID;
					//�ڶ��߳�ִ��Thread1����***************************
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

bool Table::Is_Linked()//�ж����ε���Ƿ�����
{
	return Two_Link();	
}










