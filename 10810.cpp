#include<iomanip>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n, m, i, j, k;
	vector<int> v;

	cin >> n >> m;
	for (int p = 0; p <= n; p++)
	{
		v.push_back(0);
	}
	for (int p = 0; p < m; p++)
	{
		cin >> i >> j >> k;
		for (int q = i; q <= j; q++)
		{
			v[q] = k;
		}
	}
	for (auto it = v.begin() + 1; it != v.end(); it++)
	{
		cout << *it << ' ';
	}
	return 0;
}