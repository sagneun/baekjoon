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
			if (arr[j] > arr[j + 1])
			{
				swap(arr, j, j + 1);
			}
		}
	}
}
bool next_permutation(int *arr, int n)
{
	int i = 0, j = 0;
	for (i = n - 1; i > 0; i--)
	{
		if (i > 0 && arr[i] > arr[i - 1])
		{
			break;
		}
	}
	if (i == 0)
	{
		return false;
	}
	else {
		for (j = n - 1; j >= i; j--)
		{
			if (arr[i - 1] < arr[j])
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
		arr[i] = i + 1;
		printf("%d ", arr[i]);
	}
	printf("\n");

	while (next_permutation(arr, n))
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	}

	return 0;
}