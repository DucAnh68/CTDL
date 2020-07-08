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
void Nhap(Tree &T)
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
void NLR(Tree T)
{
	if (T != NULL)
	{
		cout << T->info <<" ";
		NLR(T->pLeft);
		NLR(T->pRight);
	}
}
void LRN(Tree T)
{
	if (T != NULL)
	{
		LRN(T->pLeft);
		LRN(T->pRight);
		cout<<T->info<<" ";
	}
}
void RNL(Tree T)
{
	if (T != NULL)
	{
		RNL(T->pRight);
		cout << T->info << " ";
		RNL(T->pLeft);
	}
}
void RLN(Tree T)
{
	if (T != NULL)
	{
		RLN(T->pRight);
		RLN(T->pLeft);
		cout << T->info << " ";
	}

}
void NRL(Tree T)
{
	if (T != NULL)
	{
		cout << T->info << " ";
		NRL(T->pRight);
		NRL(T->pLeft);
	}
}
int main()
{
	Tree T;
	CreateTree(T);
	Nhap(T);
	cout<<"\nLNR: ";
	LNR(T);
	cout << "\nLRN: ";
	LRN(T);
	cout << "\nRNL: ";
	RNL(T);
	cout << "\nRLN: ";
	RLN(T);
	cout << "\nNLR: ";
	NLR(T);
	cout << "\nNRL: ";
	NRL(T);
	return 0;
}
