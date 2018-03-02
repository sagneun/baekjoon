#include<stdlib.h>
#include<stdio.h>
int main()
{
	// 줄바꿈은 아스키코드 10
	// 공백은 아스키코드 32
	// 숫자는 줄바꿈과 공백을 무시하고 받지만, 문자는 모두 인정이 되기때문에 유의해서 사용하는것이 좋다.
	/*int num;
	int v;
	int value[100];

	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
	scanf("%d", &v);
	value[i] = v;
	}

	for (int i = 0; i < num; i++)
	{
	printf("%d : %d ", i, value[i]);
	}*/

	// 11718번
	char s[111];
	int rt = 0;
	while ((rt = scanf("%[^\n]\n", s)) == 1) {
		printf("%d \n", rt);
		printf("%s\n", s);
	}

	/*
	char s[111];
	while (gets(s)) {
	printf("%s\n", s);
	}
	*/
	return 0;
}