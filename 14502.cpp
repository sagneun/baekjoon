#include<iostream>
using namespace std;
int lab[9][9];
int cpy_lab[9][9];
int possibleforwall[81];
int alive = 0;
int cnt = 0;
int findIndexToBuildWall(int n, int m)
{
	int cnt_pos = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (lab[i][j] == 0)
			{
				possibleforwall[cnt_pos] = i * m + j;
				cout << i << " , " << j << endl;
				cnt_pos++;
			}
		}
	}
	return cnt_pos;
}
int safeSpace(int n, int m)
{
	int safe = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (cpy_lab[i][j] == 0)
			{
				safe++;
			}
		}
	}
	return safe;
}
void infection(int x, int y, int n, int m)
{
	if (x < 0 || x >= n || y < 0 || y >= m || cpy_lab[x][y] != 0)
	{
		return;
	}

	if (cpy_lab[x][y] == 0)
	{
		cpy_lab[x][y] = 2;

		infection(x - 1, y, n, m);
		infection(x, y + 1, n, m);
		infection(x + 1, y, n, m);
		infection(x, y - 1, n, m);
	}

	return;
}
void printf(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << cpy_lab[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << lab[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}
void cpy(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cpy_lab[i][j] = lab[i][j];
			cout << lab[i][j] << " ";
		}
		cout << endl;
	}
}
void laboratory(int i, int depth, int cnt_pos , int n, int m)
{
	if (depth > 3 || i > cnt_pos)
	{
		return;
	}
	if (depth == 3)
	{
		cnt++;
		if (cnt == 5)
		{
			cpy(n, m);
		}
		else
		{
			memcpy(cpy_lab, lab, sizeof(lab));
		}
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < m; y++)
			{
				if (cpy_lab[x][y] == 1)
				{
					//cout << "x : " << x << ", y : " << y << endl;
				}
				if (cpy_lab[x][y] == 2)
				{
					infection(x - 1, y, n, m);
					infection(x, y + 1, n, m);
					infection(x + 1, y, n, m);
					infection(x, y - 1, n, m);
				}
			}
		}
		int safe = safeSpace(n,m);
		if (alive < safe)
		{
			cout << safe << endl;
			//printf(n, m);
			alive = safe;
		}
		return;
	}
	lab[possibleforwall[i]/m][possibleforwall[i]%m] = 1;
	laboratory(i + 1, depth + 1, cnt_pos, n, m);
	lab[possibleforwall[i]/m][possibleforwall[i]%m] = 0;
	laboratory(i + 1, depth, cnt_pos, n, m);
}
int main()
{
	int n, m, v;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v;
		//	cpy_lab[i][j] = v;
			lab[i][j] = v;
		}
	}

	int cnt_pos = findIndexToBuildWall(n, m);
	//cout << cnt_pos;
	laboratory(0, 0, cnt_pos, n, m);

	//printf("%d", cnt);
	return 0;
}