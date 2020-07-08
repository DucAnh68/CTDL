//Hàm  là hàm nạp a vào ngăn xếp s.
//Hàm  là hàm lấy một phần tử ra khỏi ngăn xếp s.
//Viết chương trình nhập số nguyên  và một dãy số nguyên bất kỳ(việc nhập sẽ kết thúc khi nhập số).

//Mỗi giá trị   trong dãy số nguyên tương đương với việc gọi  và mỗi giá trị  trong dãy số nguyên tương đương với việc gọi.Sinh viên thực hiện chức năng  khi số lượng số trong ngăn xếp lớn hơn.Ngược lại in ra “.”.

//In ra màn hình các giá trị có trong ngăn xếp.
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
	return p;
}
void Push(List &l, node *p)
{
	if (l.pHead == NULL)
		l.pTail = l.pHead = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void Pop(List &l)
{
	if (l.pHead != NULL)
	{
		node *p = new node;
		l.pHead = l.pHead->pNext;
	}
	else
	{
		cout << "Stack rong ." << endl;
	}
}
void Nhap(List &l)
{
	int n;
	int x;
	cin >> n;
	while (1)
	{
		cin >> x;
		if (x == 0)
			break;
		if (x == n)
			Pop(l);
		else
		{
			node *p = CreateNode(x);
			Push(l, p);
		}
	}			
}
void Xuat(List &l)
{
	cout << "Cac gia tri trong stack la : ";
	node *p = l.pHead;
	while (p != NULL)
	{
		cout << p->info<<" ";
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
		cout << "Stack rong.";
	}
	else
		Xuat(l);
	return 0;
}