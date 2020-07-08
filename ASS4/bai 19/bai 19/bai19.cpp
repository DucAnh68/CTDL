//Đưa hết các số chia hết cho x về đầu danh sách. Phần tử được đưa lên đầu phải đứng sau cac  phần tử được đưa lên trước đó.
#include<iostream>
using namespace std;
struct Node
{
	int info;
	Node* pNext;
};

struct List
{
	Node* pHead;
	Node* pTail;
};

void CreateList(List& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

Node* CreateNode(int x)
{
	Node* p = new Node;
	p->info = x;
	p->pNext = NULL;
	return p;
}

void AddTail(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}


void Input(List& l)
{
	int x;
	while (1)
	{
		cin >> x;
		if (x == 0) break;
		Node* p = CreateNode(x);
		AddTail(l, p);
	}
}


void Output(List l)
{
	Node * p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
}


void FindListChiaHet(List l, List &l1, List &l2, int x)
{
	for (Node* i = l.pHead; i != NULL; i = i->pNext)
	{
		if (i->info % x == 0)
		{
			Node* g = CreateNode(i->info);
			AddTail(l1, g);
		}
		else
		{
			Node* g = CreateNode(i->info);
			AddTail(l2, g);
		}
	}
}



int main()
{
	List l;
	List l1, l2;
	int x;
	CreateList(l);
	CreateList(l1);
	CreateList(l2);
	Input(l);
	cin >> x;
	if (l.pHead == NULL)
	{
		cout << "Danh sach rong.";
		return 0;
	}
	else
	{
		FindListChiaHet(l, l1, l2, x);
		if (l1.pHead == NULL)
		{
			Output(l2);
		}
		else
		{
			Output(l1);
			Output(l2);
		}
	}
	return 0;
}