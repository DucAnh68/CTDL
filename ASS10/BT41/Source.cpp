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
		if (T->info < x)
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

void LNR_re(Tree T,int &dem)
{
	if (T != NULL)
	{
		LNR_re(T->pRight, dem);
		if (T->pLeft == NULL && T->pRight == NULL)
			dem++;
		LNR_re(T->pLeft, dem);
	}
}
void LNR(Tree T)
{
	if (T != NULL)
	{
		LNR(T->pRight);
		if (T->pLeft == NULL && T->pRight == NULL)
			cout << T->info << " ";
		LNR(T->pLeft);
	}
}
int main()
{
	int n;
	cin >> n;
	Tree T;
	CreateTree(T);
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		InsertNode(T, temp);
	}
	int dem = 0;
	LNR_re(T,dem);
	cout << dem << endl;
	LNR(T);
	return 0;
}