//Sap xep cac gia tri theo thu tu tang dan
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
node* CreateNode(int n)
{
	node* p = new node;
	if (p == NULL)
		exit(-1);
	p->info = n;
	p->pNext = NULL;
	return p;
}
void AddTail(List& l, node* p)
{
	if (l.pHead == NULL)
		l.pTail = l.pHead = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void Nhap(List& l)
{
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		node* p = CreateNode(n);
		AddTail(l, p);
	}
}

void Xuat(List l)
{
	node* p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
}
void SortIncrease(List& l)
{
	for (node *p =l.pHead ; p != NULL; p= p->pNext)
		for (node *q = p->pNext; q != NULL; q = q->pNext)
		{
			if (p->info > q->info)
				swap(q->info, p->info);
		}
}
int main()
{
	List l;
	CreateList(l);
	Nhap(l);
	if (l.pHead == NULL)
	{
		cout << "Danh sach rong !!!";
	}
	else
	{
		SortIncrease(l);
		cout << "Danh sach sau khi sap xep la:  ";
		cout << endl;
		Xuat(l);
	}
	return 0;
}
