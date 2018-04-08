#include<iostream>
#include<queue>
using namespace std;
int cnt = 0;
int field[50][50];

int DFS(int c, int r, int x, int y)
{
	if (x < 0 || x >= r || y < 0 || y >= c || field[x][y] != 1)
	{
		return -1;
	}

	field[x][y] = 0;
	DFS(c, r, x - 1, y);
	DFS(c, r, x + 1, y);
	DFS(c, r, x , y - 1);
	DFS(c, r, x , y + 1);
	return 1;
}
int main()
{
	int t,c,r,k,x,y; 
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> c >> r >> k;

		for (int j = 0; j < k; j++)
		{
			cin >> y >> x;
			field[x][y] = 1;
		}
		for (int a = 0; a < r; a++)
		{
			for (int b = 0; b < c; b++)
			{
				if (DFS(c, r, a, b) == 1)
				{
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
	}
	return 0;
}