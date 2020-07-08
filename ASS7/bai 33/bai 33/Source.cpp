#include<iostream>
using namespace std;
void Nhap(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void Xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
void SelectionSort(int a[], int n)
{
	int pos,x;
	for (int i = 1; i < n ; i++)
	{
		x = a[i];
		pos = i - 1;
		while ((pos >= 0) && (a[pos] <= x))
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		cout << endl;
		cout << "Vi tri chen cua " << "a[" << i << "] la "<< pos + 1 << endl;
			a[pos + 1] = x ;
		Xuat(a, n);
	}
}
int main()
{
	int a[1000];
	int n;
	cin >> n;
	Nhap(a, n);
	if (n == 0)
		cout << "Mang rong.";
	if ((n == 1)&(a[0] == 0))
	{
		cout << "Mang rong." << endl;
	}
	else
	{
		cout << "Mang truoc khi sap xep la: ";
		Xuat(a, n);
	}
	SelectionSort(a, n);
	cout << "\nMang sau khi sap xep la: ";
	Xuat(a, n);
	return 0;
}