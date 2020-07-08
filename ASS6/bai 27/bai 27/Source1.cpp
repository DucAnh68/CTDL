#include<iostream>
using namespace std;
int binarySearchLeft(int nums[], int left, int right, int n, int target) {
	if (n == 0)
		return -1;

	while (left <= right) {

		long int mid = (left + right) / 2;
		if ((mid == 0 || target > nums[mid - 1]) && nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

int binarySearchRight(int nums[], int left, int right, int n, int target) {
	if (n == 0)
		return -1;

	while (left <= right) {

		long int mid = (left + right) / 2;
		if ((mid == n - 1 || target < nums[mid + 1]) && nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] > target) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
}

void Process(int nums[], int n, int target) {
	int batdau = binarySearchLeft(nums, 0, n - 1, n, target);

	if (batdau == -1)
	{
		cout << -1;
		return;
	}
	int ketthuc = binarySearchRight(nums, batdau, n - 1, n, target);

	int soLanXuatHien = ketthuc - batdau + 1;
	cout << soLanXuatHien << " " << batdau + 1 << " " << ketthuc + 1;


}
void input(int nums[], int keys[], int &n, int &t)
{
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	for (int i = 0; i < t; i++)
	{
		cin >> keys[i];
	}
}

int main()
{
	int n, t;
	cin >> n;
	cin >> t;
	int *nums = new int[n];
	int *keys = new int[t];
	input(nums, keys, n, t);
	for (int i = 0; i < t; i++)
	{
		Process(nums, n, keys[i]);
		cout << endl;
	}
	delete[] nums;
	delete[] keys;
	system("pause");
	return 0;
}