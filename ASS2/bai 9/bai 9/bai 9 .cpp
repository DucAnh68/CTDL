// xoa cac phan tu y giong nhau va khong dao danh sach
#include<iostream>
using namespace std;
struct node
{
	int info;
	node * pNext;
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

	p->pNext = NULL;
	p->info = x;
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
void nhap(List &l)
{
	while (1)
	{
		int x;
		cin >> x;
		if (x == 0)
			break;
		node *p = CreateNode(x);
		AddTail(l, p);
	}
}
void xuat(List &l)
{
	node *p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
}
void xoa(List &l, int x, int &count)
{

	node *temp = l.pHead;

	while (temp != NULL && temp->info == x)
	{
		count++;
		l.pHead = temp->pNext;
		temp = l.pHead;
	}

	while (temp != NULL)
	{
		while (temp != NULL && temp->info != x)
		{
			node *prev = temp;
			temp = temp->pNext;
		}

		if (temp == NULL)
			count++;
		prev->pNext = temp->pNext;
		temp = prev->pNext;
	}
}
void ReverseList(List &l)
{
	node* p = l.pHead;
	node* current = NULL;
	node* previous = NULL;

	while (p != NULL) {
		current = p;
		p = p->pNext;
		current->pNext = previous;
		previous = current;
	}
	p = current;
	l.pHead = l.pTail;
}
int main()
{
	int x;
	int count = 0;
	List l;
	CreateList(l);
	nhap(l);
	if (l.pHead == NULL)
		cout << "Danh sach rong.";
	else
	{
		cin >> x;
		xoa(l, x, count);
		if (count == 0 && l.pHead != NULL)
		{
			cout << "Khong tim thay " << x << " trong danh sach:" << endl;
			xuat(l);
		}

		if (l.pHead == NULL)
		{
			cout << "Danh sach rong.";
		}
		else if (l.pHead != NULL && count != 0)
		{
			xuat(l);
		}
	}
	return 0;
}