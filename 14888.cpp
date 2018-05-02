#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
char calculator[4] = { '+', '-', '*', '/' };
string cal; 
int A[11];
int biggest = -1000000000;
int smallest = 1000000000;
int resultOf(int c_i, int now, int A_i)
{
	int result;
	if (cal[c_i] == '0') // '+'
	{
		result = now + A[A_i];
	}
	if (cal[c_i] == '1') // '-'
	{
		result = now - A[A_i];
	}
	if (cal[c_i] == '2') // '*'
	{
		result = now * A[A_i];
	}
	if (cal[c_i] == '3') // '/'
	{
		result = now / A[A_i];
	}
	return result;
}
void calculation(int now, int i, int n) // depth는 cal배열을 통해 모든 연산자를 사용하였는가 판단하기 위해 사용된다.
{
	if (i == n - 1)
	{
		if (now > biggest)
		{
			biggest = now;
		}
		if (now < smallest)
		{
			smallest = now;
		}
		return;
	}
	calculation(resultOf(i, now, i + 1), i + 1, n);
}
int main()
{
	int n, v, c;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> v;
		A[i] = v;
	}
	
	for (int i = 0; i < 4; i++)
	{
		cin >> v;
		if (v > 0)
		{
			for (int j = 0; j < v; j++)
			{
				cal = cal + to_string(i);
			}
		}
	}

	do {
		calculation(A[0], 0, n);
	} while (next_permutation(cal.begin(), cal.end()));
	
	printf("%d\n", biggest);
	printf("%d", smallest);
	
	return 0;
}