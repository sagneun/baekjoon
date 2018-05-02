#include<iostream>
#include<string.h>
#include<string>
#include<math.h>
using namespace std;
string gear[5];
int visited[5];

void DFS(int location, int dir)
{
	string c ,now, org;
	if (visited[location] == 1)
	{
		return;
	}
	org = now = gear[location];
	if (dir == 1) // 시계방향
	{
		c = now[7]; 
		now.erase(7, 1); now.insert(0, c);
	}
	else // 반시계방향
	{
		c = now[0];
		now.append(c); now.erase(0, 1);
	}
	gear[location] = now;
	visited[location] = 1;

	// 왼쪽 톱니
	if (location > 1)
	{
		if (gear[location - 1][2] != org[6])
		{
			DFS(location - 1, dir*-1);
		}
	}
	// 오른쪽 톱니
	if (location < 4)
	{
		if (gear[location + 1][6] != org[2])
		{
			DFS(location + 1, dir*-1);
		}
	}
	return;
}
int main()
{
	int k, location, dir, cnt = 0;
	cin >> gear[1];
	cin >> gear[2];
	cin >> gear[3];
	cin >> gear[4];

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> location >> dir;
		DFS(location, dir);
		memset(visited, 0, sizeof(visited));
	}
	
	for (int i = 1; i < 5; i++)
	{
		if (gear[i][0] == '1')
		{
			cnt += pow(2, i - 1);
		}
	}
	printf("%d", cnt);
	return 0;
}