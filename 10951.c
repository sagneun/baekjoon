#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b;
	int result[100];
	int i = 0;

	while (scanf("%d %d", &a, &b) == 2)
	{
		result[i++] = a + b;
	}

	for (int j = 0; j < i; j++)
	{
		printf("%d \n", result[j]);
	}
	return 0;
}