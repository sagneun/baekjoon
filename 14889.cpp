#include<iostream>
#include<string>
using namespace std;

int res = 987654321;

int S[21][21];
int db[21];
int now[21];
bool visited[21];

void fillOfMap(int depth, int i, int n)
{
	if (depth > n / 2 || i > n)
	{
		return;
	}
	if (depth == n / 2)
	{
		int start = 0, link = 0;
		for (int i = 0; i < n; i++)
		{
			if (visited[i] == false)
			{
				now[depth] = db[i];
				depth += 1;
			}
		}
		for (int i = 0; i < n / 2 - 1; i++)
		{
			for (int j = i + 1; j < n / 2; j++)
			{
				start += S[now[i]][now[j]] + S[now[j]][now[i]];
			}
		}
		for (int i = n / 2; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				link += S[now[i]][now[j]] + S[now[j]][now[i]];
			}
		}
		start = abs(start - link);
		if (res > start)
		{
			res = start;
		}
		return;
	}
	now[depth] = db[i]; visited[i] = true;
	fillOfMap(depth + 1, i + 1, n);
	visited[i] = false;
	fillOfMap(depth, i + 1, n);
}

int main()
{
	int n, v;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> v;
			S[i][j] = v;
		}
		db[i - 1] = i;
	}
	fillOfMap(0, 0, n);
	printf("%d", res);
	return 0;
}