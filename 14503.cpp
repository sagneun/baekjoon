#include<iostream>
using namespace std;
bool clean[51][51];
int area[51][51];
int cnt = 0;


bool possibleOftheLeft(int r, int c, int n, int m, int dir)
{
	if (dir == 0)
	{
		c--;
	}
	else if (dir = 1)
	{

	}
	else if (dir == 2)
	{

	}
	else
	{

	}
	if (r < 0 || c < 0 || r >= n || c >= m || clean[r][c] == true || area[r][c] == 1) // 범위로부터 벗어나거나 청소된 공간 혹은 벽인 경우에는 false return!
	{
		return false;
	}
	return true;
}
void cleanTheHouse(int r, int c, int dir, int n, int m)
{
	if (clean[r][c] == true || area[r][c] == 1)
	{
		return;
	}

	int next;

	clean[r][c] = true;
	
	if (dir == 0)
	{
		next = 3;
	}
	else
	{
		next = dir - 1;
	}

	if(possible())


}
int main()
{
	// 0 : 북, 1 : 동, 2 : 남, 3 : 서
	
	return 0;
}