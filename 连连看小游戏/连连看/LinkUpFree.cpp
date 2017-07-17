// LinkUpFree.cpp : Defines the entry point for the application.

#include "StdAfx.h"
#include "resource.h"
#include "Table.h"
#include <graphics.h>

#define MAX_LOADSTRING 50
#define IDC_MYICON                      2
#define IDS_APP_TITLE                   103
#define IDM_ABOUT                       104
#define IDM_EXIT                        105
#define IDS_HELLO                       106
#define IDI_LINKUPFREE                  107
#define IDI_SMALL                       108
#define IDC_LINKUPFREE                  109
#define IDC_STATIC                      -1

HINSTANCE hInst;												// ����һ��ʵ��
TCHAR szTitle[MAX_LOADSTRING];									// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];							// The title bar text
int lose = 1, t_time = 30;
HDC	windowDC=NULL;
HDC bufferDC=NULL;
HDC pictureDC00 = NULL;
HDC pictureDC0=NULL;HDC pictureDC1=NULL;HDC pictureDC2=NULL;HDC pictureDC3=NULL;HDC pictureDC4=NULL;HDC pictureDC5=NULL;
HDC pictureDC6=NULL;HDC pictureDC7=NULL;HDC pictureDC8=NULL;HDC pictureDC9=NULL;HDC pictureDC10=NULL;HDC pictureDC11=NULL;
HDC pictureDC12=NULL;HDC pictureDC13=NULL;HDC pictureDC14=NULL;HDC pictureDC15=NULL;HDC pictureDC16=NULL;HDC pictureDC17=NULL;
HDC pictureDC18=NULL;HDC pictureDC19=NULL;HDC pictureDC20=NULL;HDC pictureDC21=NULL;HDC pictureDC22=NULL;HDC pictureDC23=NULL;
HDC pictureDC24=NULL;HDC pictureDC25=NULL;HDC pictureDC26=NULL;HDC pictureDC27=NULL;HDC pictureDC28=NULL;HDC pictureDC29=NULL;
HDC pictureDC30=NULL;HDC pictureDC31=NULL;HDC pictureDC32=NULL;HDC pictureDC33=NULL;HDC pictureDC34=NULL;HDC pictureDC35=NULL;

HBITMAP bufferBMP=NULL;

HBITMAP PictureBMP00 = NULL;
HBITMAP PictureBMP0=NULL;HBITMAP PictureBMP1=NULL;HBITMAP PictureBMP2=NULL;HBITMAP PictureBMP3=NULL;HBITMAP PictureBMP4=NULL;
HBITMAP PictureBMP5=NULL;HBITMAP PictureBMP6=NULL;HBITMAP PictureBMP7=NULL;HBITMAP PictureBMP8=NULL;HBITMAP PictureBMP9=NULL;
HBITMAP PictureBMP10=NULL;HBITMAP PictureBMP11=NULL;HBITMAP PictureBMP12=NULL;HBITMAP PictureBMP13=NULL;HBITMAP PictureBMP14=NULL;
HBITMAP PictureBMP15=NULL;HBITMAP PictureBMP16=NULL;HBITMAP PictureBMP17=NULL;HBITMAP PictureBMP18=NULL;HBITMAP PictureBMP19=NULL;
HBITMAP PictureBMP20=NULL;HBITMAP PictureBMP21=NULL;HBITMAP PictureBMP22=NULL;HBITMAP PictureBMP23=NULL;HBITMAP PictureBMP24=NULL;
HBITMAP PictureBMP25=NULL;HBITMAP PictureBMP26=NULL;HBITMAP PictureBMP27=NULL;HBITMAP PictureBMP28=NULL;HBITMAP PictureBMP29=NULL;
HBITMAP PictureBMP30=NULL;HBITMAP PictureBMP31=NULL;HBITMAP PictureBMP32=NULL;HBITMAP PictureBMP33=NULL;HBITMAP PictureBMP34=NULL;
HBITMAP PictureBMP35=NULL;

HPEN PEN=NULL;
HBRUSH BRUSH=NULL;

Table my_table;
int ClientWidth=0;
int ClientHeight=0;                                                    //��������

ATOM				MyRegisterClass(HINSTANCE hInstance);			//ע�ᴰ�����
BOOL				InitInstance(HINSTANCE, int);					//��ʼ������
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);			//���������Ϣ
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);				//�Ի�������

void GameImageInit(HWND hWnd);
void DeleteAllObject();
void GameView(HWND hWnd);
HDC choiceDC(int);

// ������
int APIENTRY WinMain(HINSTANCE hInstance,							//APIENTRY ��������Լ��  ��ǰʵ�����
                     HINSTANCE hPrevInstance,						//����ʵ�����
                     LPSTR     lpCmdLine,							//������������ָ���ָ��
                     int       nCmdShow)							//��ʾ��ʽ
{

	MSG msg;						//��Ϣ�ṹ��
	HACCEL hAccelTable;				//����һ�����������

	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_LINKUPFREE, szWindowClass, MAX_LOADSTRING); 

	MyRegisterClass(hInstance);


	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_LINKUPFREE); // C��ʾ���� T��win32  ������ٽ���


	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))         //������ټ���
		{
			TranslateMessage(&msg);										//�ú������������Ϣת��Ϊ�ַ���Ϣ
			DispatchMessage(&msg);	 									
		}//��������Ϣ���ݸ�����ϵͳ��Ȼ�����ϵͳȥ�������ǵĻص�������Ҳ����˵�����ڴ���Ĺ��̺����д�����Ϣ
	}

	return msg.wParam;
}



ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;				              //WNDCLASSEX����һ����̨��

	wcex.cbSize = sizeof(WNDCLASSEX);   

	wcex.style			= CS_HREDRAW | CS_VREDRAW;// ���崰����ʽ
	wcex.lpfnWndProc	= (WNDPROC)WndProc;       //ǰ׺ lpfn ��ʾ�ó�Ա��һ��ָ�����ĳ�ָ��
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;	//��Щ����ֻ����Ϊ���ڹ��̶�����һЩ������ڴ�ռ䣬����ʵ��������ʹ�����ǡ�
	wcex.hInstance		= hInstance;			//���̾�� 
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_LINKUPFREE);//��ͨ�����ڴ���Դ��װ��һ��ͼ��ͼ��
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW );//���
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);//���� 
	wcex.lpszMenuName	= NULL;//�˵�ָ�� (LPCSTR)IDC_LINKUPFREE
	wcex.lpszClassName	= szWindowClass;//�������� 
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);//�ʹ����������Сͼ��

	return RegisterClassEx(&wcex);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    HWND hWnd;//�������;��


    hInst = hInstance; // Store instance handle in our global variable

    hWnd = CreateWindow(szWindowClass, "��[F1]-�����Ų�", WS_OVERLAPPEDWINDOW,
                     CW_USEDEFAULT, 0, 820, 682, NULL, NULL, hInstance, NULL);
	//�򿪱�������
	mciSendString("open ����.mp3 alias mymusic", NULL, 0, NULL);
	// ��������
	mciSendString("play mymusic", NULL, 0, NULL);

	HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("C:\\Users\\sunyichen\\Desktop\\������\\���.cur"),
			IMAGE_CURSOR, 0, 0, LR_LOADFROMFILE);

	SetClassLong(hWnd, GCL_HCURSOR, (long)hcur);

	if (!hWnd)
	{
	  return FALSE;
	}
	/////////////////////////
	RECT rt;
	GetClientRect(hWnd,&rt);
	ClientWidth=rt.right-rt.left;
	ClientHeight=rt.bottom-rt.top;

	////////////////////////
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

	GameImageInit(hWnd);

	my_table.Set_Size(ClientWidth,ClientHeight);
	my_table.InitTable();

    return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)//�ص�����
{
	int mouse_x,mouse_y;
	int x=0;
	int	y=0;
	int lose = 1;
	int wmId, wmEvent;
	PAINTSTRUCT ps;			//�˽ṹ��������ϢӦ�ó���ʹ��������һ��ӵ�и�Ӧ�ô��ڿͻ���
	HDC hdc;				//�豸���
	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);

	switch (message) 
	{

		case WM_LBUTTONDOWN://��������

			mouse_x=LOWORD(lParam);// ����ڿͻ��������Ͻǵ�Xƫ��ֵ
			if(mouse_x>ClientWidth)
				mouse_x=ClientWidth;
			else if(mouse_x<0)
				mouse_x=0;

			mouse_y=HIWORD(lParam);
			if(mouse_y>ClientHeight)
				mouse_y=ClientHeight;
			else if(mouse_y<0)
				mouse_y=0;

			x=(int)(mouse_x/(ClientWidth/10))+1;//�൱������x
			y=(int)(mouse_y/(ClientHeight/8))+1;

			if(my_table.tableArrary[y][x].choice==0&&my_table.tableArrary[y][x].type>=0) //�����һģ��û�б�ѡ���Ҵ���
			{
				if((my_table.Get_first_click().choice==0)&&(my_table.Get_second_click().choice==0))//���֮ǰû�е��һ��ģ��
				{
					my_table.Set_first_click(x,y);//�ͽ���һ��ģ����Ϊ���ǵ�һ�ε����ģ��
				}
				else if((my_table.Get_first_click().choice==1)&&my_table.Get_second_click().choice==0)
				{
					my_table.Set_second_click(x,y);
					if(my_table.Is_Linked())//�������ͼƬ����������������������
					{
						my_table.tableArrary[y][x].type=-1;
						my_table.count--;
						my_table.tableArrary[my_table.Get_first_click().y][my_table.Get_first_click().x].type=-1;
						my_table.count--;
						my_table.Delete_first_click(my_table.Get_first_click().x,my_table.Get_first_click().y);
						my_table.Delete_second_click(x,y);
					}
					else
					{
						my_table.Delete_first_click(my_table.Get_first_click().x,my_table.Get_first_click().y);
						my_table.Delete_second_click(x,y);
					}
				}
				else 
				{

				}
			}
			else if(my_table.tableArrary[y][x].choice==1)
			{
				if((my_table.tableArrary[y][x].choice==my_table.Get_first_click().choice)&&
				   (my_table.tableArrary[y][x].type==my_table.Get_first_click().type)&&
				   (my_table.tableArrary[y][x].x/ClientWidth==my_table.Get_first_click().x)&&
				   (my_table.tableArrary[y][x].y/ClientHeight==my_table.Get_first_click().y))
				{
					my_table.Delete_first_click(x,y);
				}
			}


			break;

		case WM_SIZE://�ı������ڿͻ������ִ�С
			DeleteAllObject();
			ReleaseDC(hWnd,windowDC);
			GameImageInit(hWnd);
			break;

		case WM_KEYDOWN://��һ����ϵͳ��������ʱ����Ϣ���͸����м��̽���Ĵ��ڣ����ڱ���Ϸ��F1
			switch(wParam)
			{
				case VK_F1:
					my_table.InitTable();
					break;
			}


		case WM_PAINT:	//���»���

			if(my_table.count>0)
			{

				GameView(hWnd);
			}
			else
			{
				my_table.InitTable();
			}		
			break;

		case WM_DESTROY:		//���ڽ���
			DeleteAllObject();
			ReleaseDC(hWnd,windowDC);
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }

   return 0;
}

// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}

void GameView(HWND hWnd)
{
	int PictureWidth=0;
	int PictureHeight=0;

	RECT rt;
	GetClientRect(hWnd,&rt);
	ClientWidth=rt.right-rt.left;
	ClientHeight=rt.bottom-rt.top;
	
	PictureWidth=ClientWidth/10;
	PictureHeight=ClientHeight/8;

	HDC t_DC=NULL;

	BitBlt(bufferDC,0,0,ClientWidth,ClientHeight,pictureDC0,0,0,SRCCOPY);

	

	for(int i=1;i<A_HEIGHT+1;i++)//����ͼƬ
	{
		for(int j=1;j<A_WEITH+1;j++)
		{
			t_DC=choiceDC(my_table.tableArrary[i][j].type);
			BitBlt(bufferDC,my_table.tableArrary[i][j].x-PictureWidth,my_table.tableArrary[i][j].y-PictureHeight,PictureWidth,PictureHeight,t_DC,0,0,SRCCOPY);		
		}
	}

	for(int m=1;m<A_HEIGHT+1;m++)//��������
	{
		for(int n=1;n<A_WEITH+1;n++)
		{
			if(my_table.tableArrary[m][n].choice==1)
			{
				/*setcolor(RGB(255, 200, 0));*/
				Rectangle(bufferDC,(n-1)*PictureWidth,(m-1)*PictureHeight,(n-1)*PictureWidth+PictureWidth,(m-1)*PictureHeight+PictureHeight);
			}
		}
	}

	BitBlt(windowDC,0,0,ClientWidth,ClientHeight,bufferDC,0,0,SRCCOPY);

}


HDC choiceDC(int type)//��ͬ��type��Ӧ��ͬ��ͼƬ
{
	if(type==1)
		return pictureDC1;
	if(type==2)
		return pictureDC2;
	if(type==3)
		return pictureDC3;
	if(type==4)
		return pictureDC4;
	if(type==5)
		return pictureDC5;
	if(type==6)
		return pictureDC6;
	if(type==7)
		return pictureDC7;
	if(type==8)
		return pictureDC8;
	if(type==9)
		return pictureDC9;
	if(type==10)
		return pictureDC10;
	if(type==11)
		return pictureDC11;
	if(type==12)
		return pictureDC12;
	if(type==13)
		return pictureDC13;
	if(type==14)
		return pictureDC14;
	if(type==15)
		return pictureDC15;
	if(type==16)
		return pictureDC16;
	if(type==17)
		return pictureDC17;
	if(type==18)
		return pictureDC18;
	if(type==19)
		return pictureDC19;
	if(type==20)
		return pictureDC20;
	if(type==21)
		return pictureDC21;
	if(type==22)
		return pictureDC22;
	if(type==23)
		return pictureDC23;
	if(type==24)
		return pictureDC24;
	if(type==25)
		return pictureDC25;
	if(type==26)
		return pictureDC26;
	if(type==27)
		return pictureDC27;
	if(type==28)
		return pictureDC28;
	if(type==29)
		return pictureDC29;
	if(type==30)
		return pictureDC30;
	if(type==31)
		return pictureDC31;
	if(type==32)
		return pictureDC32;
	if(type==33)
		return pictureDC33;
	if(type==34)
		return pictureDC34;
	if(type==35)
		return pictureDC35;
	else
		return NULL;
}


void GameImageInit(HWND hWnd)//ͼƬ�ĳ�ʼ��
{
	RECT rt;
	int ClientWidth=0;
	int ClientHeight=0;
	GetClientRect(hWnd,&rt);

	ClientWidth=rt.right-rt.left;
	ClientHeight=rt.bottom-rt.top;

	my_table.Set_Size(ClientWidth,ClientHeight);

	PEN=CreatePen(PS_INSIDEFRAME,5,RGB(255,0,0));//��������
	BRUSH=(HBRUSH)GetStockObject(NULL_BRUSH);//������ˢ

	windowDC=GetDC(hWnd);
	bufferDC=CreateCompatibleDC(windowDC);//����һ����ָ���豸���ݵ��ڴ��豸�����Ļ�����DC��


	//DC Insert
	pictureDC00 = CreateCompatibleDC(windowDC);
	pictureDC0=CreateCompatibleDC(windowDC); 
	pictureDC1=CreateCompatibleDC(windowDC);
	pictureDC2=CreateCompatibleDC(windowDC);
	pictureDC3=CreateCompatibleDC(windowDC);
	pictureDC4=CreateCompatibleDC(windowDC);
	pictureDC5=CreateCompatibleDC(windowDC);
	pictureDC6=CreateCompatibleDC(windowDC);
	pictureDC7=CreateCompatibleDC(windowDC);
	pictureDC8=CreateCompatibleDC(windowDC);
	pictureDC9=CreateCompatibleDC(windowDC);
	pictureDC10=CreateCompatibleDC(windowDC);
	pictureDC11=CreateCompatibleDC(windowDC);
	pictureDC12=CreateCompatibleDC(windowDC);
	pictureDC13=CreateCompatibleDC(windowDC);
	pictureDC14=CreateCompatibleDC(windowDC);
	pictureDC15=CreateCompatibleDC(windowDC);
	pictureDC16=CreateCompatibleDC(windowDC);
	pictureDC17=CreateCompatibleDC(windowDC);
	pictureDC18=CreateCompatibleDC(windowDC);
	pictureDC19=CreateCompatibleDC(windowDC);
	pictureDC20=CreateCompatibleDC(windowDC);
	pictureDC21=CreateCompatibleDC(windowDC);
	pictureDC22=CreateCompatibleDC(windowDC);
	pictureDC23=CreateCompatibleDC(windowDC);
	pictureDC24=CreateCompatibleDC(windowDC);
	pictureDC25=CreateCompatibleDC(windowDC);
	pictureDC26=CreateCompatibleDC(windowDC);
	pictureDC27=CreateCompatibleDC(windowDC);
	pictureDC28=CreateCompatibleDC(windowDC);
	pictureDC29=CreateCompatibleDC(windowDC);
	pictureDC30=CreateCompatibleDC(windowDC);
	pictureDC31=CreateCompatibleDC(windowDC);
	pictureDC32=CreateCompatibleDC(windowDC);
	pictureDC33=CreateCompatibleDC(windowDC);
	pictureDC34=CreateCompatibleDC(windowDC);
	pictureDC35=CreateCompatibleDC(windowDC);

	//BMP Insert
	bufferBMP=CreateCompatibleBitmap(windowDC,ClientWidth,ClientHeight);
	PictureBMP00 = (HBITMAP)LoadImage(NULL, "picture00.bmp", IMAGE_BITMAP, ClientWidth, ClientHeight, LR_LOADFROMFILE);
	PictureBMP0=(HBITMAP)LoadImage(NULL,"picture0.bmp",IMAGE_BITMAP,ClientWidth,ClientHeight,LR_LOADFROMFILE);
	PictureBMP1=(HBITMAP)LoadImage(NULL,"picture1.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP2=(HBITMAP)LoadImage(NULL,"picture2.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP3=(HBITMAP)LoadImage(NULL,"picture3.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP4=(HBITMAP)LoadImage(NULL,"picture4.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP5=(HBITMAP)LoadImage(NULL,"picture5.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP6=(HBITMAP)LoadImage(NULL,"picture6.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP7=(HBITMAP)LoadImage(NULL,"picture7.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP8=(HBITMAP)LoadImage(NULL,"picture8.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP9=(HBITMAP)LoadImage(NULL,"picture9.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP10=(HBITMAP)LoadImage(NULL,"picture10.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP11=(HBITMAP)LoadImage(NULL,"picture11.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP12=(HBITMAP)LoadImage(NULL,"picture12.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP13=(HBITMAP)LoadImage(NULL,"picture13.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP14=(HBITMAP)LoadImage(NULL,"picture14.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP15=(HBITMAP)LoadImage(NULL,"picture15.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP16=(HBITMAP)LoadImage(NULL,"picture16.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP17=(HBITMAP)LoadImage(NULL,"picture17.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP18=(HBITMAP)LoadImage(NULL,"picture18.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP19=(HBITMAP)LoadImage(NULL,"picture19.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP20=(HBITMAP)LoadImage(NULL,"picture20.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP21=(HBITMAP)LoadImage(NULL,"picture21.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP22=(HBITMAP)LoadImage(NULL,"picture22.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP23=(HBITMAP)LoadImage(NULL,"picture23.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP24=(HBITMAP)LoadImage(NULL,"picture24.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP25=(HBITMAP)LoadImage(NULL,"picture25.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP26=(HBITMAP)LoadImage(NULL,"picture26.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP27=(HBITMAP)LoadImage(NULL,"picture27.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP28=(HBITMAP)LoadImage(NULL,"picture28.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP29=(HBITMAP)LoadImage(NULL,"picture29.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP30=(HBITMAP)LoadImage(NULL,"picture30.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP31=(HBITMAP)LoadImage(NULL,"picture31.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP32=(HBITMAP)LoadImage(NULL,"picture32.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP33=(HBITMAP)LoadImage(NULL,"picture33.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP34=(HBITMAP)LoadImage(NULL,"picture34.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);
	PictureBMP35=(HBITMAP)LoadImage(NULL,"picture35.bmp",IMAGE_BITMAP,ClientWidth/10,ClientHeight/8,LR_LOADFROMFILE);

	//SelectObject

	SelectObject(bufferDC,bufferBMP);//SelectObject������

	SelectObject(bufferDC,PEN);//SelectObject ����
	SelectObject(bufferDC,BRUSH);//SelectObject ��ˢ

	SelectObject(pictureDC00, PictureBMP00);
	SelectObject(pictureDC0,PictureBMP0);
	SelectObject(pictureDC1,PictureBMP1);
	SelectObject(pictureDC2,PictureBMP2);
	SelectObject(pictureDC3,PictureBMP3);
	SelectObject(pictureDC4,PictureBMP4);
	SelectObject(pictureDC5,PictureBMP5);
	SelectObject(pictureDC6,PictureBMP6);
	SelectObject(pictureDC7,PictureBMP7);
	SelectObject(pictureDC8,PictureBMP8);
	SelectObject(pictureDC9,PictureBMP9);
	SelectObject(pictureDC10,PictureBMP10);
	SelectObject(pictureDC11,PictureBMP11);
	SelectObject(pictureDC12,PictureBMP12);
	SelectObject(pictureDC13,PictureBMP13);
	SelectObject(pictureDC14,PictureBMP14);
	SelectObject(pictureDC15,PictureBMP15);
	SelectObject(pictureDC16,PictureBMP16);
	SelectObject(pictureDC17,PictureBMP17);
	SelectObject(pictureDC18,PictureBMP18);
	SelectObject(pictureDC19,PictureBMP19);
	SelectObject(pictureDC20,PictureBMP20);
	SelectObject(pictureDC21,PictureBMP21);
	SelectObject(pictureDC22,PictureBMP22);
	SelectObject(pictureDC23,PictureBMP23);
	SelectObject(pictureDC24,PictureBMP24);
	SelectObject(pictureDC25,PictureBMP25);
	SelectObject(pictureDC26,PictureBMP26);
	SelectObject(pictureDC27,PictureBMP27);
	SelectObject(pictureDC28,PictureBMP28);
	SelectObject(pictureDC29,PictureBMP29);
	SelectObject(pictureDC30,PictureBMP30);
	SelectObject(pictureDC31,PictureBMP31);
	SelectObject(pictureDC32,PictureBMP32);
	SelectObject(pictureDC33,PictureBMP33);
	SelectObject(pictureDC34,PictureBMP34);
	SelectObject(pictureDC35,PictureBMP35);

}

void DeleteAllObject()
{
	DeleteDC(pictureDC00);
	DeleteDC(pictureDC0);
	DeleteDC(pictureDC1);
	DeleteDC(pictureDC2);
	DeleteDC(pictureDC3);
	DeleteDC(pictureDC4);
	DeleteDC(pictureDC5);
	DeleteDC(pictureDC6);
	DeleteDC(pictureDC7);
	DeleteDC(pictureDC8);
	DeleteDC(pictureDC9);
	DeleteDC(pictureDC10);
	DeleteDC(pictureDC11);
	DeleteDC(pictureDC12);
	DeleteDC(pictureDC13);
	DeleteDC(pictureDC14);
	DeleteDC(pictureDC15);
	DeleteDC(pictureDC16);
	DeleteDC(pictureDC17);
	DeleteDC(pictureDC18);
	DeleteDC(pictureDC19);
	DeleteDC(pictureDC20);
	DeleteDC(pictureDC21);
	DeleteDC(pictureDC22);
	DeleteDC(pictureDC23);
	DeleteDC(pictureDC24);
	DeleteDC(pictureDC25);
	DeleteDC(pictureDC26);
	DeleteDC(pictureDC27);
	DeleteDC(pictureDC28);
	DeleteDC(pictureDC29);
	DeleteDC(pictureDC30);
	DeleteDC(pictureDC30);
	DeleteDC(pictureDC31);
	DeleteDC(pictureDC32);
	DeleteDC(pictureDC33);
	DeleteDC(pictureDC34);
	DeleteDC(pictureDC35);
	
	DeleteDC(bufferDC);
	

	DeleteObject(PEN);//SelectObject ����
	DeleteObject(BRUSH);//SelectObject ��ˢ

	DeleteObject(PictureBMP00);
	DeleteObject(PictureBMP0);
	DeleteObject(PictureBMP1);
	DeleteObject(PictureBMP2);
	DeleteObject(PictureBMP3);
	DeleteObject(PictureBMP4);
	DeleteObject(PictureBMP5);
	DeleteObject(PictureBMP6);
	DeleteObject(PictureBMP7);
	DeleteObject(PictureBMP8);
	DeleteObject(PictureBMP9);
	DeleteObject(PictureBMP10);
	DeleteObject(PictureBMP10);
	DeleteObject(PictureBMP11);
	DeleteObject(PictureBMP12);
	DeleteObject(PictureBMP13);
	DeleteObject(PictureBMP14);
	DeleteObject(PictureBMP15);
	DeleteObject(PictureBMP16);
	DeleteObject(PictureBMP17);
	DeleteObject(PictureBMP18);
	DeleteObject(PictureBMP19);
	DeleteObject(PictureBMP20);
	DeleteObject(PictureBMP20);
	DeleteObject(PictureBMP21);
	DeleteObject(PictureBMP22);
	DeleteObject(PictureBMP23);
	DeleteObject(PictureBMP24);
	DeleteObject(PictureBMP25);
	DeleteObject(PictureBMP26);
	DeleteObject(PictureBMP27);
	DeleteObject(PictureBMP28);
	DeleteObject(PictureBMP29);
	DeleteObject(PictureBMP30);
	DeleteObject(PictureBMP20);
	DeleteObject(PictureBMP31);
	DeleteObject(PictureBMP32);
	DeleteObject(PictureBMP33);
	DeleteObject(PictureBMP34);
	DeleteObject(PictureBMP35);

	DeleteObject(bufferBMP);//SelectObject������
}