#include<iostream>
using namespace std;
void swap(int *arr, int a, int b)
{
	int v = arr[a];
	arr[a] = arr[b];
	arr[b] = v;
	return;
}
void sort(int *arr, int first, int end)
{
	for (int i = 0; i < end - first; i++)
	{
		for (int j = first; j < end - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				swap(arr, j, j + 1);
			}
		}
	}
}
bool prev_permutation(int *arr, int n)
{
	int i = 0, j = 0;
	for (i = n - 1; i > 0; i--)
	{
		if (arr[i - 1] > arr[i])
		{
			break;
		}
	}
	if (i == 0)
	{
		printf("-1");
		return false;
	}
	else {
		for (j = n - 1; j >= i; j--)
		{
			if (arr[i - 1] > arr[j])
			{
				break;
			}
		}
		swap(arr, i - 1, j);
		sort(arr, i, n);
		return true;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int arr[10000];
	int n, v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v;
		arr[i] = v;
	}
	if (prev_permutation(arr, n))
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d ", arr[i]);
		}
	}

	return 0;
}