//Tìm số lượng số có giá trị bằng K trong dãy A đã cho. Biết rằng dãy A đã được sắp xếp tăng dần.
#include<iostream>
using namespace std;
void Nhap(int a[], int N)
{
	for (int i = 0; i < N; i++)
		cin >> a[i];
}
int BinarySearch(int a[], int sau, int N)
{
	int l = 0, r = N - 1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (a[m] == sau)
			return m;
		else {
			if (a[m] > sau)
				r = m - 1;
			else
				l = m + 1;
		}
	}
	return -1;
}
int First(int a[], int x, int k)
{
	int i = x-1;
	while ((i >= 0) && (a[i] == k))
	{
		i--;
	}
	return i+1;
}
int Later(int a[], int n, int x, int k)
{
	int i = x + 1;
	while ((i < n) && (a[i] == k))
	{
		i++;
	}
	return i - 1;
}
int main()
{
	int N,T; 
	cin >> N >> T;
	int *a = new int[N];
	int *K = new int[T];
	Nhap(a, N);
	Nhap(K, T);
	for (int i = 0; i < T; i++)
	{
		int x = BinarySearch(a, K[i], N);
		if (x == -1)
		{
			cout << x << endl;
		}
		else
		{
			int tren = First(a, x, K[i]);
			int duoi = Later(a, N, x, K[i]);
			cout << duoi - tren + 1;
			cout << " " << tren + 1 << " " << duoi + 1 << endl;
		}
	}
	return 0;
}