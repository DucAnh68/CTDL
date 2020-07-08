//Viết chương trình đổi một số nguyên dương từ hệ thập phân sang hệ nhị phân dùng stack
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
};
void CreateList(List& l)
{
	l.pHead = NULL;
}
node* CreateNode(int x);
void AddHead(List& l, node* p);
void enstack(List& l, int x);
void destack(List& l);
bool isEmpty(List l);
int main()
{
	List st;
	CreateList(st);
	long long x;
	cin >> x;
	enstack(st, x);
	destack(st);
	return 0;
}
node* CreateNode(int x)
{
	node *p = new node;
	p->info = x;
	p->pNext = NULL;
	return p;
}
void AddHead(List& l, node* p)
{
	if (isEmpty(l) == 1)
	{
		l.pHead = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void enstack(List& l, int x)
{
	while (x > 0)
	{
		int t = x % 2;
		node *p =CreateNode(t);
		AddHead(l, p);
		x /= 2;
	}
}
void destack(List &l)
{
	node *p = l.pHead;
	while (p != NULL)
	{
		cout << p->info;
		p = p->pNext;
	}
}
bool isEmpty(List l)
{
	if (l.pHead == NULL)
		return 1;
	return 0;
}