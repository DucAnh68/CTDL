#include<iostream>
#include<vector>
using namespace std;
struct Index
{
	int x = 0;
	int y = 0;
};
void HieuChinh(long long a[], int pos, int n, vector<Index>& ans, bool t)
{
	int j = 2 * pos + 1;
	Index a1;
	while (j <= n)
	{
		if (j < n)
			if (a[j] > a[j + 1])
				j++;
		if (a[j] >= a[pos])
			return;
		else
		{
			swap(a[j], a[pos]);
			if (t)
			{
				a1.x = pos;
				a1.y = j;
				ans.push_back(a1);
			}
			pos = j;
			j = pos * 2 + 1;
		}
	}
}
void CreateHeap(long long a[], int n, vector<Index>& ans)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		HieuChinh(a, i, n - 1, ans, 1);
}
void HeapSort(long long a[], int n, vector<Index>& ans)
{
	CreateHeap(a, n, ans);
	int r = n - 1;
	while (r > 0)
	{
		swap(a[0], a[r]);
		r--;
		if (r > 0)
			HieuChinh(a, 0, r, ans, 0);
	}
}
int main()
{
	vector<Index> ans;
	int n = 0;
	cin >> n;
	long long* a = new long long[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << "Day truoc khi sap xep: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	HeapSort(a, n, ans);
	cout << "Day sau khi sap xep: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << "Cac hoan vi duoc thuc hien trong heap: " << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].x << " " << ans[i].y << endl;
	return 0;
}