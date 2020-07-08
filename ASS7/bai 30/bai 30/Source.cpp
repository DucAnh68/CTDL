#include<iostream>
using namespace std;
struct Node
{
	long long Tu;
	long long Mau;
	double Chia;
	Node *pNext;
};
struct List
{
	Node *pHead;
	Node *pTail;
};
void CreateList(List &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
Node *CreateNode(long long T,long long M)
{
	Node *p = new Node;
	p->Tu = T;
	p->Mau = M;
	p->Chia = double(T)/double(M);
	p->pNext = NULL;
	return p;
}
void AddTail(List &l, Node *p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void Nhap(List &l)
{
	long long Tu;
	long long Mau;
	while (1)
	{
		cin >> Tu;
		cin >> Mau;
		if (Mau == 0)
			break;
		Node *p = CreateNode(Tu, Mau);
		AddTail(l, p);
	}
}
void Xuat(List &l)
{
	for (Node *p = l.pHead; p != NULL; p = p->pNext)
	{
		cout << p->Tu << "/" << p->Mau<<" ";
	}
	cout << endl;
}
void Process(List l, long long xtu, long long xmau, double x)
{
	List k;
	CreateList(k);
	bool test = 0;

	for (Node *p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->Chia == x)
		{
			test = 1;
			long long tam1 = p->Tu;
			long long tam2 = p->Mau;
			Node *p = CreateNode(tam1, tam2);
			AddTail(k, p);
		}
	}
	if (test == 0)
		cout << "Khong co phan so nao bang " << xtu << "/" << xmau << " trong danh sach.";
	else
	{
		cout << "Cac phan so bang " << xtu << "/" << xmau << " co trong danh sach la: ";
		Xuat(k);
	}

	cout << endl;
}
bool isEmpty(List &l)
{
	if (l.pHead == NULL)
		return 1;
	return 0;
}
int main()
{
	List l;
	CreateList(l);
	Nhap(l);
	if (isEmpty(l)==1)
	{
		cout << "Danh sach rong.";
		return 0;
	}
	cout << "Danh sach vua nhap la: ";
	Xuat(l);
	long long Tu, Mau;
	double x;
	cin >> Tu;
	cin >> Mau;
	x = double(Tu) / double(Mau);
	Process(l, Tu, Mau, x);
	return 0;
}