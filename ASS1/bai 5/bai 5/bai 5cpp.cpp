// Hãy tách danh sách vừa nhập thành 2 danh sách l1 và l2 sao cho:

//l1 bao gồm các số chẵn không trùng nhau.
//l2 bao gồm các số lẻ không trùng nhau.
//Đều được xếp theo thứ tự đầu vào
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
		cout << "Danh sach rong !!!";
}
void Xuat(List &l)
{
	for (node * p = l.pHead; p != NULL; p = p->pNext)
		cout << p->info << " ";
}
int DemSoPhanTu(List l)
{
	int dem = 0;
	for (node * p = l.pHead; p != NULL; p = p->pNext)
		dem++;
	return dem;
}
void Split(List l, List &l1, List &l2)
{
	node* p;
	for (p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->info % 2 == 0)
		{
			node* p2 = new node;
			if (p2 == NULL)
				exit(-1);
			p2->info = p->info;
			p2->pNext = NULL;
			if (l1.pHead == NULL)
			{
				l1.pHead = p2;
				l1.pTail = l1.pHead;
			}
			else
			{
				node* e = l1.pHead;
				while (e != NULL)
				{
					if (e->info == p2->info) {
						goto xy;
					}
					e = e->pNext;
				}
				l1.pTail->pNext = p2;
				l1.pTail = p2;
			}

		}
		else
		{
			node* p3 = new node;
			if (p3 == NULL)
				exit(-1);
			p3->info = p->info;
			p3->pNext = NULL;
			if (l2.pHead == NULL)
			{
				l2.pHead = p3;
				l2.pTail = l2.pHead;
			}
			else
			{
				node* e = l2.pHead;
				while (e != NULL)
				{
					if (e->info == p3->info) {
						goto xy;
					}
					e = e->pNext;
				}
				l2.pTail->pNext = p3;
				l2.pTail = p3;
			}

		}
	xy:
		{

		}
	}
}
	
int main()
{
	List l, l1, l2;
	CreateList(l);
	CreateList(l1);
	CreateList(l2);
	Nhap(l);
	if (DemSoPhanTu(l) == 0)
		cout << "Danh sach rong." << endl;
	else
	{
		cout << "Danh sach vua nhap la: ";
		Xuat(l);
		cout << endl;
		Split(l, l1, l2);
		cout << "Cac so chan trong danh sach la: ";
		Xuat(l1);
		cout << endl;
		cout << "Cac so le trong danh sach la: ";
		Xuat(l2);
		cout << endl;
	}
	return 0;
}