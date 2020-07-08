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
	int min,i,j;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		cout << "i=" << i <<":"<< endl;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] > a[min])
				min = j;
		}
		cout << "Max = a[" << min << "] = " << a[min] << endl;
		swap(a[min], a[i]);
		cout << "Mang sau khi sap xep " << i + 1 << " phan tu dau tien la: ";
		Xuat(a, n);
		cout << endl;
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
	else
	{
		cout << "Mang truoc khi sap xep la: ";
		Xuat(a, n);
		cout << endl;
		SelectionSort(a, n);
		cout << "Mang sau khi sap xep la: ";
		Xuat(a, n);
	}
	return 0;
}