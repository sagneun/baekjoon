#include<stdlib.h>
#include<stdio.h>
int main()
{
	// �ٹٲ��� �ƽ�Ű�ڵ� 10
	// ������ �ƽ�Ű�ڵ� 32
	// ���ڴ� �ٹٲް� ������ �����ϰ� ������, ���ڴ� ��� ������ �Ǳ⶧���� �����ؼ� ����ϴ°��� ����.
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

	// 11718��
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