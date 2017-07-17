// Table.h: interface for the Table class.

#include "LinkList.h"

#define A_WEITH 10			//����10��
#define A_HEIGHT 8		//����8��


struct PicturePoint
{
	int x;//����
	int y;
	int type;//ͼƬ����
	bool choice;//�ڼ��ε��
};

typedef struct Table Table;
struct Table
{

	PicturePoint first_click;
	PicturePoint second_click;
	int ClientHeight;
	int ClientWidth;

	int count;//���ӵ�����
	PicturePoint tableArrary[A_HEIGHT+2][A_WEITH+2];
	PicturePoint Get_first_click();
	PicturePoint Get_second_click();
	void Set_Size(int,int);
	int  Get_Width();
	int  Get_Height();
	void Table_Set_count(int);
	int  Table_Get_count();
	void Set_first_click(int ,int);
	void Set_second_click(int ,int);
	void Delete_first_click(int ,int);
	void Delete_second_click(int ,int);
	bool X_through(int ,int ,int);
	bool Y_through(int ,int ,int);
	bool Two_Link();
	bool Is_Linked();
	bool InitTable();
	Table();
};

