#include<iostream>
using namespace std;
struct node
{
	float info;
	node* pLeft;
	node* pRight;
};
typedef node* Tree;
void CreateTree(Tree& T)
{
	T = NULL;
}
node* CreateNode(float x)
{
	node* p = new node;
	p->info = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
int InsertNode(Tree& T, float x)
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
void LNR(Tree T)
{
	if (T != NULL)
	{
		LNR(T->pLeft);
		cout << T->info << " ";
		LNR(T->pRight);
	}
}
node* SearchNode(Tree T, float x)
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
	Tree T = NULL;
	int n;
	cin >> n;
	float temp;
	float tb = 0;
	for (float i = 0; i < n; i++)
	{
		cin >> temp;
		tb = tb + temp;
		InsertNode(T, temp);
	}
	tb /= n;
	if (SearchNode(T, tb) == NULL)
		cout << 1;
	else
		cout << 0;
	cout << endl;
	LNR(T);

	return 0;

}