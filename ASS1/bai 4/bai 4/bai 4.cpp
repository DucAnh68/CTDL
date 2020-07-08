// dem so nguyen to o vi tri le !!!!
#include<iostream>
#include<math.h>
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
	node * p = new node;
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
		node * p = CreateNode(x);
		AddTail(l, p);
	}
	if (l.pHead == NULL)
	{
		cout << "Danh sach rong !!!";
	}
}
void Xuat(List &l)
{
	node * p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
}

bool snt(int x)
{
	if (x < 2)
		return 0;
	for (int i = 2 ; i <= sqrt(x); i++)
		if (x % i == 0)
			return 0;
	return 1;
}
void Test(List &l)
{
	int count = 0;
	int value = 1;
	node * p = l.pHead;
	while (p != NULL)
	{
		if (value % 2 != 0)
			if (snt(p->info) == 1)
				count++;
		value++;
		p = p->pNext;
	}
	cout << "Danh sach tren co  " << count << " so nguyen to o vi tri le .";
}
int main()
{
	List l;
	CreateList(l);
	Nhap(l);
	Xuat(l);
	if (l.pHead != NULL)
	{
		cout << endl;
		Test(l);
	}
	return 0;
}