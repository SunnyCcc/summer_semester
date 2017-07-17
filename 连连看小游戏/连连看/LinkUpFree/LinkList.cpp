// LinkList.cpp: implementation of the LinkList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "LinkList.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LinkList::LinkList()
{
	count=0;
	Head=new Node;
	Head->date=-1;
	Head->next=NULL;
}

LinkList::~LinkList()
{
	delete Head;
}

bool LinkList::Insert(int date)
{
	Node *s1=new Node;
	Node *s2=new Node;

	if(s1==NULL||s2==NULL)
	{
		return 0;
	}

	s1->date=date;
	s1->next=Head->next;
	Head->next=s1;
	count++;

	s2->date=date;
	s2->next=Head->next;
	Head->next=s2;
	count++;

	return true;
}

int LinkList::Delete(int n)
{
	int ret_n=0;
	Node *x=Head;
	Node *y=Head;
	n--;
	while(n>0)
	{
		x=x->next;
		n--;
	}
	y=x->next;

	x->next=y->next;
	ret_n=y->date;

	count--;
	delete y;

	return ret_n;	
}

int LinkList::GetCount()
{
	return count;
}






