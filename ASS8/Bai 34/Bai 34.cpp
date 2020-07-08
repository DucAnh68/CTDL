#include<iostream>
#include<vector>
using namespace std;
struct Index
{
	int x;
	int y;
};
void Xuat(vector<long long>a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a.at(i)<<" ";
	cout << endl;
}
void QuickSort(vector<long long>&a, int l, int r, vector<Index>& b )
{
	int i, j;
	long long x = a[(l+r)/2];
	i = l; j = r;
	while (i <= j)
	{
		while (a[i] > x)
			i++;
		while (a[j] < x)
			j--;

		if (i <= j) {
			swap(a.at(i), a.at(j));
			if (i != j)
			{
				Index temp;
				temp.x = i + 1;
				temp.y = j + 1;
				b.push_back(temp);

			}
			i++; j--;
		}
	}
	if (j > l)
		QuickSort(a, l, j,b);
	if (i < r)
		QuickSort(a, i, r,b);
}
int main()
{
	int n;
	cin >> n;
	long long x;
	vector<long long>a;
	for (int i= 0;i<n;i++)
	{
		cin >> x;
		a.push_back(x);
	}
	cout << "Day truoc khi sap xep: ";
	Xuat(a, n);
	vector<Index> b;
	QuickSort(a, 0, n - 1,b);
	cout << "Day sau khi sap xep: ";
	Xuat(a, n);
	cout << "Cac hoan vi duoc thuc hien trong Quick Sort:" << endl;
	for (int  i = 0; i < b.size(); i++)
		cout << b.at(i).x << " " << b.at(i).y << endl;
	return 0;
}
