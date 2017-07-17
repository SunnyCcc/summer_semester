
#include "LinkList.h"
#include <windows.h>
#include "StdAfx.h"

PLIST LinkList(PLIST list)
{
	list->count=0;
	list->Head= (PNODE)malloc(sizeof(Node));
	list->Head->date=-1;
	list->Head->next=NULL;
	return list;
}


int Insert(PLIST list,int data)
{
	Node *s1;
	Node *s2;

	s1 = (PNODE)malloc(sizeof(Node));
	s2 = (PNODE)malloc(sizeof(Node));

	if(s1==NULL||s2==NULL)
	{
		return 0;
	}
	
	s1->date=data;
	s1->next=list->Head->next;
	list->Head->next=s1;
	list->count++;

	s2->date=data;
	s2->next= list->Head->next;
	list->Head->next=s2;
	list->count++;

	return 1;
}

int Delete(PLIST list,int n)
{
	int ret_n=0;
	Node *x= list->Head;
	Node *y= list->Head;
	n--;
	while(n>0)
	{
		x=x->next;
		n--;
	}
	y=x->next;

	x->next=y->next;
	ret_n=y->date;

	list->count--;
	free(y);

	return ret_n;	
}

int GetCount(PLIST list)
{
	return list->count;
}
