//Cho dãy số nguyên A1, A2, A3, …AN gồm N phần tử.Mỗi phần tử thuộc dãy A và số K có giá trị tuyệt đối không quá 1012.

//Yêu cầu : Tìm số lượng số có giá trị không bé hơn K trong dãy A đã cho.Biết rằng dãy A đã được sắp xếp tăng dần.
#include<iostream>
using namespace std;
void Nhap(int a[], int &N,int &T)
{
	for (int i = 0; i < N; i++)
		cin >> a[i];
}
void NhapSau(int K[], int T)
{
	for (int i = 0; i < T; i++)
		cin >> K[i];
}
int BinarySearch(int a[], int sau, int N)
{
	int l = 0, r = N - 1;
	int position = N;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (a[m] >= sau)
		{
			position = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	return (N-position);
}
int main()
{
	int N = 0, T=0;
	cin >> N >> T;
	int *a = new int[N];
	int *K = new int[T];
	Nhap(a, N, T);
	NhapSau(K, T);
	for (int i = 0; i < T; i++)
	{
		cout << BinarySearch(a, K[i], N) << endl;
	}
	return 0;
}