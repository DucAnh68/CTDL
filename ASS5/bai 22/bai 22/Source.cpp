//Viết chương trình đảo ngược số nguyên dương dùng hàng đợi
#include <iostream>
using namespace std;
struct node
{
	int info;
	node* pNext;
};
struct List
{
	node* pHead;
	node* pTail;
};
void CreateList(List& l);
node* CreateNode(int x);
void AddTail(List& l, node* p);
void enqueue(List& l, int x);
void dequeue(List& l);
bool isEmpty(List l);
int main()
{
	List q;
	CreateList(q);
	long long x;
	cin >> x;
	if (x == 0)
		cout << "0";
	else
	{
		int h = 0;
		while (x % 10 == 0)
			x = x / 10;
		while (x != 0)
		{
			h = x % 10;
			enqueue(q, h);
			x = x / 10;
		}
		dequeue(q);
	}
	return 0;
}
void CreateList(List &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
node *CreateNode(int x)
{
	node *p = new node;
	p->info = x;
	p->pNext = NULL;
	return p;
}
void AddTail(List& l, node* p)
{
	if (isEmpty(l) == 1)
	{
		l.pHead = p;
		l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
bool isEmpty(List l)
{
	if (l.pHead == NULL)
		return 1;
	return 0;
}
void enqueue(List& l, int x)
{
	node *p = CreateNode(x);
	AddTail(l, p);
}
void dequeue(List& l)
{
	node *p = l.pHead;
	while (p != NULL)
	{
		cout << p->info;
		p = p->pNext;
	}
}