//Đếm và in ra giá trị có số lần xuất hiện nhiều nhất trong danh sách.
#include<iostream>
using namespace std;
struct node
{
	int info;
	int cout = 1;
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
	p->pNext = NULL;
	return p;
}
void AddTail(List &l, node *p)
{
	if (l.pHead == NULL)
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
}
void Xuat(List &l)
{
	node*p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
}
int RemoveAfterQ(List &l, node *p, node *q)
{
	if (p != NULL)
	{
		if (p == l.pTail)
			l.pTail = q;
		q->pNext = p->pNext;
		delete p;
	}
	return 1;
}
void Search(List l)
{
	int dem = 1;
	for (node* i = l.pHead; i != NULL; i = i->pNext)
	{
		node* q = i;
		for (node* j = i->pNext; j != NULL;)
		{
			if (i->info == j->info)
			{
				node* temp = j->pNext;
				i->cout++;
				RemoveAfterQ(l, j, q);
				j = temp;
			}
			else
			{
				q = j;
				j = j->pNext;
			}
		}
		if (i->cout > dem)
			dem = i->cout;
	}
	node* p = l.pHead;
	while (p != NULL)
	{
		if (p->cout == dem)
			cout << p->info << ": " << dem << endl;
		p = p->pNext;
	}
}
int main()
{
	List l;
	CreateList(l);
	Nhap(l);
	if (l.pHead == NULL)
	{
		cout << " Danh sach rong !!!";
	}
	else
	{
		Xuat(l);
		cout << endl;
		Search(l);
	}
	return 0;
}