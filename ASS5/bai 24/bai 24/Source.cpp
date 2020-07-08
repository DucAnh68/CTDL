//Viết chương trình đếm các cặp dấu ngoặc tròn tương ứng trong một biểu thức điều kiện viết bằng ngôn ngữ C / C++.

//Dữ liệu vào :

//Gồm một dòng duy nhất là chuỗi các kí tự liên tiếp nhau(có chứa dấu cách).
//Số lượng kí tự nhập vào không quá 2.10 mux 5
//Dữ liệu ra :

//Nếu sau khi xóa các cặp ngoặc hợp lệ từ input và các kí tự khác ngoài ‘(’ và ‘)’ ta vẫn thu được một chuỗi khác rỗng  thì xuất ra “Dat dau ngoac bi sai.”.

//Nếu sau khi xóa các cặp ngoặc hợp lệ từ input và các kí tự khác ngoài ‘(’ và ‘)’ ta vẫn thu được một chuỗi mà bên trong chỉ toàn kí tự ‘(’ thì xuất ra “Thieu dau ngoac dong.”.

	//Nếu sau khi xóa các cặp ngoặc hợp lệ từ input và các kí tự khác ngoài ‘(’ và ‘)’ ta vẫn thu được một chuỗi mà bên trong chỉ toàn kí tự ‘)’ thì xuất ra “Thieu dau ngoac mo.”.

	//Nếu sau khi xóa các cặp ngoặc hợp lệ từ input và các kí tự khác ngoài ‘(’ và ‘)’ ta vẫn thu được một chuỗi có độ dài bằng rỗng thì suất ra số lượng ngoặc đúng theo cách sau : “So cap dau ngoac tron la : <số ngoặc đúng>”
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
struct node
{
	int info;
	node* pNext;
};
struct List
{
	node* pHead;
};
void CreateList(List& l)
{
	l.pHead = NULL;
}
node* CreateNode(int x);
void AddHead(List& l, node* p);
void enstack(List& l, int x);
void destack(List& l);
bool isEmpty(List l);
int main()
{
	List l;
	CreateList(l);

	bool open = false;
	bool close = false;
	int dem = 0;

	char x;
	cin.get(x);

	while (x != '\n' && x != 0 && x != '\0') {
		if (x == '(') {
			enstack(l, 1);
		}
		if (x == ')') {
			if (isEmpty(l)) {
				open = true;
			}
			else {
				destack(l);
				dem++;
			}
		}
		x = '\n';
		cin.get(x);
	}

	if (!isEmpty(l)) close = true;

	if (open && close) {
		cout << "Dat dau ngoac bi sai.";
	}
	else {
		if (open) {
			cout << "Thieu dau ngoac mo.";
		}
		if (close) {
			cout << "Thieu dau ngoac dong.";
		}
		if (!open && !close) {
			cout << "So cap dau ngoac tron la: " << dem;
		}
	}
	return 0;
}

node* CreateNode(int x)
{
	node* p = new node();
	p->info = x;
	p->pNext = NULL;
	return p;
}

void AddHead(List& l, node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

bool isEmpty(List l) {
	return l.pHead == nullptr;
}

void enstack(List& l, int a) {
	AddHead(l, CreateNode(a));
}

void destack(List& l) {
	node* p = l.pHead;
	if (p == nullptr) return;
	l.pHead = p->pNext;
}