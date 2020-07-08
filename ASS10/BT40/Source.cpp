#include<iostream>
using namespace std;
struct node
{
	int info;
	node* pLeft;
	node* pRight;
};
typedef node* Tree;
void CreateTree(Tree& T)
{
	T = NULL;
}
node* CreateNode(int x)
{
	node* p = new node;
	p->info = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
int InsertNode(Tree& T, int x)
{
	if (T)
	{
		if (T->info == x)
			return 0;
		if (T->info > x)
			return InsertNode(T->pLeft, x);
		else
		{
			return InsertNode(T->pRight, x);
		}
	}
	T = new node;
	if (T == NULL)
		return -1;
	T->info = x;
	T->pLeft = T->pRight = NULL;
	return 1;
}
void Nhap(Tree& T)
{
	int x;
	while (1)
	{
		cin >> x;
		if (x == 0)
			break;
		InsertNode(T, x);
	}
}
void LNR(Tree T)
{
	if (T != NULL)
	{
		LNR(T->pLeft);
		cout << T->info << " ";
		LNR(T->pRight);
	}
}
node* SearchNode(Tree T, int x)
{
	if (T != NULL)
	{
		if (T->info == x)
			return T;
		else if (T->info > x)
			return SearchNode(T->pLeft, x);
		else if (T->info < x)
			return SearchNode(T->pRight, x);
	}
	return NULL;
}
int main()
{
	Tree T;
	int n;
	CreateTree(T);
	Nhap(T);
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		if (SearchNode(T, n) == NULL)
			cout << "NO"<<endl;
		else
			cout << "YES"<<endl;
	}
	return 0;
}
