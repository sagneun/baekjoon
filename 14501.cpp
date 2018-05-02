#include<iostream>
using namespace std;
int maxProfit = 0;
int T[15];
int P[15];
void DFS(int i, int nowProfit, int n)
{
	if (i > n)
	{
		return;
	}
	
	while (T[i] == 1 && i < n)
	{
		nowProfit += P[i];
		i++;
	}

	if (nowProfit > maxProfit)
	{
		maxProfit = nowProfit;
	}
	
	if (i == n)
	{
		return;
	}

	DFS(i + T[i], nowProfit + P[i], n);
	DFS(i + 1 , nowProfit, n);
	
}
int main()
{
	int n, t, p;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t >> p;
		T[i] = t; P[i] = p;
	}
	DFS(0, 0, n);
	printf("%d", maxProfit);
	return 0;
}