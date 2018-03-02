#include<stdio.h>
#include<stdlib.h>
int main()
{
	char c;
	while ((c = getchar()) && c != EOF) {
		printf("%c", c);
	}
	return 0;
}