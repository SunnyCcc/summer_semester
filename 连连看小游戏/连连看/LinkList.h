typedef struct node
{
	int date;
	struct node *next;
}Node,*PNODE;

typedef struct LinkList  
{
	PNODE Head;
	int count;
}LIST,*PLIST;

int Insert(PLIST list, int data);
int Delete(PLIST list,int n);
int GetCount(PLIST list);
PLIST LinkList(PLIST list);
//virtual ~LinkList();