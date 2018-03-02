#include<stdio.h>
#include<stdlib.h>
int main()
{
	char s[11];

	while (scanf("%[]", s))
	{
		printf("%10s", s);
	}
}