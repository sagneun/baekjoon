#include<iostream>
using namespace std;
int ans = 0;

bool toCheck[15]; // 해당 열의 queen 존재 여부 확인 y
bool toCheck1[30]; // ↗↙대각선 방향 queen 존재 여부 확인 x + y
bool toCheck2[30]; // ↖↘대각선 방향 queen 존재 여부 확인 x - y + n-1

bool isPossible(int x, int y, int n)
{
	if (toCheck[y] == true || toCheck1[x+y] == true || toCheck2[x-y+n-1] == true)
	{
		return false;
	}
	return true;
}
void DFS(int row, int n)
{
	if (row == n)
	{
		ans = ans + 1;
		return;
	}

	for (int col = 0; col < n; col++)
	{
		if (isPossible(row, col, n))
		{
			toCheck[col] = true; toCheck1[row + col] = true; toCheck2[row - col + n - 1] = true;
			DFS(row + 1, n);
			toCheck[col] = false; toCheck1[row + col] = false; toCheck2[row - col + n - 1] = false;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	DFS(0, n);
	cout << ans;
	return 0;
}