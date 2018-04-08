#include<iostream>
using namespace std;
long long factorial(int v)
{
	if (v <= 1)
	{
		return 1;
	}
	return factorial(v - 1)*v;
}
int countNumberOfUnusedNumberUnderV(int *used, int v, int n)
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i < v && used[i] != 1)
		{
			cnt++;
		}
	}
	return cnt;
}
void theSequencethArray(int *arr, int n, long long k)
{
	long long result;
	int used[21];

	for (int i = 1; i <= n; i++)
	{
		for (int j = n; j > 0 ; j--)
		{
			if ((used[j] != 1) && (result = k - factorial(n-i)*countNumberOfUnusedNumberUnderV(used,j, n)) >= 0)
			{
				arr[i] = j;
				used[j] = 1;
				k = result;
				break;
			}
		}
	}
}
long long theSequenceOfArray(int *arr, int n)
{
	long long order = 1;
	int used[21] = { 0 };
	for (int i = 0 ; i < n-1  ; i++)
	{
		if (arr[i] == 1 && used[1] == 0)
		{
			used[1] = 1;
		}
		else if(arr[i] > 1)
		{
			int cnt = countNumberOfUnusedNumberUnderV(used, arr[i], n);
			used[arr[i]] = 1;
			order += cnt * factorial(n - i - 1);
		}
	}
	return order;
}
int main()
{
	int arr1[21];
	int arr2[20];
	int n;
	long long k;
	cin >> n; // 1 <= n <= 20
	cin >> k; 
	
	if (k == 1)
	{
		cin >> k; // k번째 수열의 배열, 1 <= k <= n!
		
		theSequencethArray(arr1, n, k - 1);
		for (int i = 1; i <= n; i++)
		{
			printf("%d ", arr1[i]);
		}
	}
	else // k = 2, 임이의 순열을 나타내는 n개의 수 입력 후 몇 번째 수열인지 출력
	{
		for (int i = 0; i < n; i++)
		{
			cin >> k;
			arr2[i] = k;
		}
		printf("%lld", theSequenceOfArray(arr2,n));
	}
	return 0;
}