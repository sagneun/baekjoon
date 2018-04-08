#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int W[10][10];
	int n, x;
	int w = -1, tmp = 0;

	cin >> n; // 2 <= n <= 10

	vector<int> d(n);
	for (int i = 0; i < n; i++)
	{
		d[i] = i;
		for (int j = 0; j < n; j++)
		{
			cin >> x;
			W[i][j] = x;
		}
	}

	do {
		bool ok = true;
		tmp = 0;

		for (int i = 0; i < n - 1 ; i++)
		{
			if (W[d[i]][d[i + 1]] == 0)
			{
				ok = false;
				break;
			}
			else {
				tmp += W[d[i]][d[i + 1]];
			}
		}
		if (ok == true && W[d[n-1]][0] > 0)
		{
			tmp += W[d[n - 1]][0];
			if (w == -1 || w > tmp)
			{
				w = tmp;
			}
		}
	} while (next_permutation(d.begin() + 1, d.end())); // n=4라면, 1 2 3 4 = 4 1 2 3 = 3 4 1 2 = 2 3 4 1 이므로, 중복 계산이 발생한다, 따라서 1 2 3 4 , 1 3 2 4 처럼 시작점을 고정하고 순열을 구하면 중복계산은 존재하지 않으므로 d.begin()+1 !
	
	printf("%d", w);
	return 0;
}