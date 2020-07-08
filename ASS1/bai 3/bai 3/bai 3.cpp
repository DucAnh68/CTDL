#include<iostream>
using namespace std;
struct node
{
	int info;
	node *pNext;
};
struct List
{
	node *pHead;
	node *pTail;
};
void CreateList(List &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
node *CreateNode(int x)
{
	node *p = new node;
	if (p == NULL)
		exit(1);
	p->info = x;
	p->pNext =NULL  ;
	return p;
}
void AddTail(List &l,node *p)
{
	if(l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void Nhap(List &l)
{
	int x;
	while (1)
	{
		cin >> x;
		if (x == 0)
			break;
		node *p = CreateNode(x);
		AddTail(l, p);
	}
	if (l.pHead == NULL)
		cout << "Danh sach rong !!";
}
void Xuat(List &l)
{
	node *p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
}
int Lenght(List &l)
{
	int dodai = 0;
	for (node *p = l.pHead; p != NULL; p = p->pNext)
		dodai++;
	return dodai;
}
int main()
{
	List l;
	CreateList(l);
	Nhap(l);
	if (l.pHead != NULL)
	{
		cout << "Danh sach vua nhap co " << Lenght(l) << " phan tu ";
		Xuat(l);
	}
	return 0;
}