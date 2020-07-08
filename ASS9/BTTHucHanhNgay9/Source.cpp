#include<iostream>
using namespace std;
void Nhap(int a[],int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void Xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i]<<" ";
}
void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = new int[n2]; int* R = new int[n1];
    for (int i = 0; i < n2; i++)
        L[i] = a[m+1+i];
    for (int j = 0; j < n1; j++)
        R[j] = a[l+j];
    i = 0, j = 0, k = l;
    Xuat(L, n2);
    Xuat(R, n1);
    cout << endl;
    while (i < n2 && j < n1)
    {
        if (L[i] >= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n2)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n1)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int l, int r)
{
    if (l<r)
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
int main()
{
    int n;
    int a[1000];
    cin >> n;
    Nhap(a, n);
    mergeSort(a, 0, n - 1);
    Xuat(a, n);
    return 0;
}