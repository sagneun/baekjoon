#include<iostream>
#include<string>
#include<string.h> // memset
#include<queue>
using namespace std;
// �Ҽ��� ���Ҷ��� �����佺�׳׽��� ü! ( ��� �ڿ����� �Ҽ����� ������ ǥ���ȴ�), �� �ڸ��� �Ҽ� ������ 1013 ~ 9973
bool prime[10001]; // default value of unset boolean type : default
bool visited[10001];
int d[10001];
queue<int> que;


void isPrimeNumber(string str, int idx, int tochange)
{
	int prev = stoi(str);
	str[idx] = tochange+'0';
	int next = stoi(str);

	if (prime[next] == true && visited[next] == false)
	{
		d[next] = d[prev] + 1;
		visited[next] = true;
		que.push(next);
		return;
	}
}
void primeNumber(int f, int t)
{
	int next, swt=0;
	string pn;
	que.push(f);
	visited[f] = true;
	d[f] = 0;

	while (!que.empty())
	{
		next = que.front(); que.pop();
		if (next == t)
		{
			printf("%d\n", d[next]);
			swt = 1; // ����� ���Դٸ� ���̻� ������ �ʿ䰡 ���� ������ que�� �ʱ�ȭ�� ���� pop�� ���ش�. �� ��Ȳ�� ���� ����ġ ����
		}
		if (swt == 0)
		{
			pn = to_string(next);

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (i == 0 && j == 0)
					{
						continue;
					}
					else if (pn[i] != j + '0')
					{
						isPrimeNumber(pn, i, j);
					}
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int test,f,t;

	//-----------------�����佺�׳׽��� ü---------------------//
	for (int i = 2; i <= 10000; i++) {
		if (prime[i] == false) {
			for (int j = i*i; j <= 10000; j += i) {
				prime[j] = true;
			}
		}
	}
	for (int i = 0; i <= 10000; i++) {
		prime[i] = !prime[i];
	}
	//---------------------------------------------------------//


	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> f >> t; 
		primeNumber(f,t);
		memset(d, 0, sizeof(d));
		memset(visited, false, sizeof(visited));
	}
	return 0;
}