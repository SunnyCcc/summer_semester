// LinkList.h: interface for the LinkList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINKLIST_H__A350C59E_88C5_4962_8250_5088500AF818__INCLUDED_)
#define AFX_LINKLIST_H__A350C59E_88C5_4962_8250_5088500AF818__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct node
{
	int date;
	struct node *next;
}Node;

class LinkList  
{
private:
	Node *Head;
	int count;
public:
	bool Insert(int date);
	int Delete(int n);
	int GetCount();

	LinkList();
	virtual ~LinkList();

};

#endif // !defined(AFX_LINKLIST_H__A350C59E_88C5_4962_8250_5088500AF818__INCLUDED_)
