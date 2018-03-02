#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num = 0;
	int cnt;
	int v;

	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++)
	{
		scanf("%1d", &v);
		num = num + v;
	}
	printf("sum : %d", num);
	return 0;
}