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
	if (r < 0 || c < 0 || r >= n || c >= m || clean[r][c] == true || area[r][c] == 1) // �����κ��� ����ų� û�ҵ� ���� Ȥ�� ���� ��쿡�� false return!
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
	// 0 : ��, 1 : ��, 2 : ��, 3 : ��
	
	return 0;
}