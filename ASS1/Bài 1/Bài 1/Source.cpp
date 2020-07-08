// đếm số phần tử xuất hiện trong danh sách
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
	p->pNext = NULL;
}
void AddTail(List &l, node * p)
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
}
void Xuat(List &l)
{
	for (node * p = l.pHead; p != NULL; p = p->pNext)
	{
		cout << p->info << " ";
	}
	cout << endl;
}
void Process(List &l)
{
	int dem = 1;
	node *i = l.pHead;
	node * j;
	node * k;
	while (i != NULL)
	{
		node * j = i->pNext;
		k = i;
		dem = 1;
		while (j != NULL) {
			if (i->info == j->info) {
				dem++;
				if (j = l.pTail) {
					node *h = j;
					k->pNext = j->pNext;
					delete h;
					j = k->pNext;
					l.pTail = k;
				}
				else
				{
					node* h = j;
					k->pNext = j->pNext;
					delete h;
					j = k->pNext;
				}
			}
			else
			{
				k = j;
				j = j->pNext;
			}
		}
		cout << i->info << " : " << dem;
		cout << endl;
		i = i->pNext;
	}
}
int main()
{
	List l;
	CreateList(l);
	Nhap(l);
	if (l.pHead == NULL)
	{
		cout << "Danh sach rong!!";
		return 0;
	}
	else
	{
		cout << "Danh sach vua nhap la: ";
			Xuat(l);
		cout << "So lan xuat hien tung phan tu trong danh sach la : ";
		Process(l);
	}
}