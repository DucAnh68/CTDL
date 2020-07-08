//Tìm và in ra các số nguyên tố ở vị trí chẵn. Danh sách được đánh dấu từ 1.
#include<iostream>
#include<cmath>
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
	while (1) {
		cin >> x;
		if (x == 0)
			break;
		node* p = CreateNode(x);
		AddTail(l, p);
	}
	if (l.pHead == NULL)
		cout << "Danh sach rong!! ";
}
bool Snt(int x)
{
	if (x < 2)
		return 0;
	if (x == 2)
		return 1;
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0)
			return 0;
	return 1;
}
int Search(List l)
{
	int a = 1;
	for (node * p = l.pHead; p != NULL; p = p->pNext)
	{
		if ((a % 2 == 0) && Snt(p->info) == 1)
			cout << p->info << " ";
		a++;
	}
	return a;
}
int main()
{
	List l;
	CreateList(l);
	Nhap(l);
	Search(l);
	return 0;
}