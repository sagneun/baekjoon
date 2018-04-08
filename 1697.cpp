#include<iostream>
#include<queue>
using namespace std;
queue<int> que;
int visited[100001];

void BFS(int f, int t)
{
	int distance = 0;
	que.push(f);
	int next;
	int que_size;

	while (!que.empty())
	{
		que_size = (signed int)que.size();
		for (int i = 0; i < que_size; i++)
		{
			next = que.front();
			que.pop();
			visited[next] = 1;

			if (next == t)
			{
				printf("%d", distance);
				return;
			}

			if (next + 1 <= 100000 && visited[next+1] != 1)
			{
				que.push(next + 1);
			}
			if (next - 1 >= 0 && visited[next - 1] != 1)
			{
				que.push(next - 1);
			}
			if (next * 2 > 0 && next * 2 <= 100000 && visited[next * 2] != 1)
			{
				que.push(next * 2);
			}
		}
		distance++;
	}
}
int main()
{
	int k,n;
	cin >> n >> k;

	BFS(n, k);
	return 0;
}