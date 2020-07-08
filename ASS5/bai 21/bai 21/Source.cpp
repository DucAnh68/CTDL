//Giả sử hàm enqueue(q, a) là hàm nạp a vào hàng đợi q và hàm dequeue(s) là hàm lấy một phần tử ra khỏi hàng đợi q.

//Viết chương trình nhập ký tự c và chuỗi ký tự s.Mỗi ký tự a trong chuỗi s tương đương với :

//-a != c : gọi enqueue(q, a)

//- a = c : gọi dequeue(s) và in ký tự vừa đựợc lấy ra khỏi hàng đợi lên màn hình.

//Cho biết kết quả được in lên màn hình khi chạy chương trình trên.
#include<iostream>
#include<string>
using namespace std;
struct node {
	char info;
	node* pNext;
};
struct List {
	node* pHead;
	node* pTail;
};
void CreateList(List& l);
node* CreateNode(char x);
void AddTail(List& l, node* p);
void Xuat(List l);
void enqueue(List& l, char x);
int dequeue(List& l);
bool isEmpty(List l);
int main()
{
	char c;
	cin >> c;
	string s = "";
	cin >> s;
	List queue;
	CreateList(queue);
	enqueue(queue, c);
	if (s.length() == 0)
	{
		cout << "Chuoi rong.";
		return 0;
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == c)
		{
			dequeue(queue);
		}
		else
		{
			enqueue(queue, s[i]);
		}
	}
	cout << endl;
	Xuat(queue);
	return 0;
}

void CreateList(List& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

bool isEmpty(List l)
{
	if (l.pHead == NULL) return 1;
	else return 0;
}

void AddTail(List& Q, node* p)
{

	if (isEmpty(Q) == 1)
	{
		Q.pHead = p;
		Q.pTail = Q.pHead;
	}

	else
	{
		Q.pTail->pNext = p;
		Q.pTail = p;
	}
}

node* CreateNode(char x)
{
	node* P = new node;
	P->info = x;
	P->pNext = NULL;
	return P;
}

void enqueue(List& l, char x)
{
	node* P = CreateNode(x);
	AddTail(l, P);
}

int dequeue(List& l)
{
	if (isEmpty(l) == 1)
		return 0;
	node* p = l.pHead;
	if (l.pHead != NULL)
	{
		int temp = 0;
		temp = p->info;
		l.pHead = l.pHead->pNext;
		cout << p->info;
		delete(p);
		return 1;
	}
}

int Pop(List& l, char& Item)
{
	if (isEmpty(l) == 1) return 0;
	node* p = l.pHead;
	Item = p->info;

	l.pHead = l.pHead->pNext;
	if (l.pHead == NULL)
		l.pTail == NULL;
	delete(p);
	return 1;
}

void Xuat(List l)
{
	char Item;
	if (isEmpty(l) == 1) cout << "Hang doi rong.";

	else
	{
		cout << "Cac gia tri co trong hang doi la: ";
		while (Pop(l, Item) == 1) cout << Item;
	}
}

