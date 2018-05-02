#include<iostream>
#include<string.h>
using namespace std;
int map[100][100];
bool cover[100][100];

bool cntWhen(int row, int col, int from, int dir, int n, int l)
{
	int cnt = 0;
	if (col == -1) // ÇàÀÇ Â÷·Ê
	{
		if (dir > 0)
		{
			for (int i = from; i >= 0; i--)
			{
				if (map[row][i] != map[row][from] || cover[row][i] == true)
				{
					break;
				}
				cnt++;
			}
			if (cnt >= l)
			{
				while(l--)
				{
					cover[row][from-l] = true;
				}
				return true;
			}
		}
		else
		{
			from = from + 1;
			for (int i = from; i < n; i++)
			{
				if (map[row][i] != map[row][from] || cover[row][i] == true)
				{
					break;
				}
				cnt++;
			}
			if (cnt >= l)
			{
				while (l--)
				{
					cover[row][from + l] = true;
				}
				return true;
			}
		}
	}
	else if (row == -1) // ¿­ÀÇ Â÷·Ê
	{
		if (dir > 0)
		{
			for (int i = from; i >= 0; i--)
			{
				if (map[i][col] != map[from][col] || cover[i][col] == true)
				{
					break;
				}
				cnt++;
			}
			if (cnt >= l)
			{
				while (l--)
				{
					cover[from-l][col] = true;
				}
				return true;
			}
		}
		else
		{
			from = from + 1;
			for (int i = from; i < n; i++)
			{
				if (map[i][col] != map[from][col] || cover[i][col] == true)
				{
					break;
				}
				cnt++;
			}
			if (cnt >= l)
			{
				while (l--)
				{
					cover[from+l][col] = true;
				}
				return true;
			}
		}
	}
	return false;
}
int possibleway(int n, int l)
{
	int cnt = 0, gap, swt = 0;
	for (int i = 0; i < n; i++)
	{
		swt = 0;
		for (int j = 0; j < n - 1; j++)
		{
			gap = map[i][j + 1] - map[i][j];
			if (abs(gap) == 1)
			{
				if (!cntWhen(i, -1, j, gap, n, l))
				{
					swt = 1;
					break;
				}
			}
			else if (abs(gap) > 1)
			{
				swt = 1;
				break;
			}
		}
		if (swt == 0)
		{
			cnt++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		memset(cover[i], false, sizeof(bool)*n);
	}

	for (int i = 0; i < n; i++)
	{
		swt = 0;
		for (int j = 0; j < n - 1; j++)
		{
			gap = map[j + 1][i] - map[j][i];
			if (abs(gap) == 1)
			{
				if (!cntWhen(-1, i, j, gap, n, l))
				{
					swt = 1;
					break;
				}
			}
			else if (abs(gap) > 1)
			{
				swt = 1;
				break;
			}
		}
		if (swt == 0)
		{
			cnt++;
		}
	}

	return cnt;
}
int main()
{
	int n, l, v;
	
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v;
			map[i][j] = v;
		}
	}
	cout << possibleway(n, l);
	return 0;
}