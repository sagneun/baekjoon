#include <iostream>
using namespace std;
int k;
int input[13]; // 6 < k < 13
int result[6];

void dfs(int start, int depth)
{
	if (depth == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			printf("%d ", result[i]);
		}
		printf("\n");
	}
	else
	{
		for (int i = start; i < k; i++)
		{
			result[depth] = input[i];
			dfs(i+1, depth + 1);
		}
	}
	return;
}
int main() 
{

	while (cin >> k && k) //0이 아닌 모든 정수는 true!!
	{
		for (int i = 0; i < k; i++)
		{
			cin >> input[i];
		}
		dfs(0,0);
		printf("\n");
	}
	return 0;
}