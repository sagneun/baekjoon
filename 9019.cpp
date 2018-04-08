#include<iostream>
#include<queue>
#include<stack>
#include<string.h> // for memset
using namespace std;
char how[10000];
bool visited[10000];
int previous[10000];
queue<int> que;

void showThePath(int now, int f)
{
	if (now == f)
	{
		printf("\n");
		return;
	}
	showThePath(previous[now], f);
	printf("%c", how[now]);
}
int whatisthenext(int v, char h)
{
	int next = -1;
	int tmp;
	if (h == 'D')
	{
		tmp = v * 2 % 10000;
	}
	if (h == 'S')
	{
		if (v == 0)
		{
			tmp = 9999;
		}
		else
		{
			tmp = v - 1;
		}
	}
	if (h == 'L')
	{
		tmp = v / 1000 + (v % 1000) * 10;
	}
	if (h == 'R')
	{
		tmp = (v % 10) * 1000 + v / 10;
	}

	if (visited[tmp] == false)
	{
		next = tmp;
	}
	return next;
}
void DSLR(int f, int t)
{
	ios_base::sync_with_stdio(false);
	int tmp, next, swt = 0;
	char order[4] = { 'D','S','L','R' };
	visited[f] = true;
	que.push(f);
	how[f] = 'F';

	while (!que.empty())
	{
		tmp = que.front(); que.pop();

		if (swt == 0)
		{
			for (int i = 0; i < 4; i++)
			{
				if ((next = whatisthenext(tmp, order[i])) != -1)
				{
					visited[next] = true;
					how[next] = order[i];
					previous[next] = tmp;
					if (next == t)
					{
						swt = 1; break;
					}
					que.push(next);
				}
			}
		}
	}
	showThePath(t, f);
}
int main()
{
	int f, t, test;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> f >> t;
		DSLR(f, t);
		memset(previous, -1, sizeof(previous));
		memset(visited, false, sizeof(visited));
		memset(how, NULL, sizeof(how));
	}
	return 0;
}