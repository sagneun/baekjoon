#include<iomanip>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n, m;
	vector<int> v;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		v.push_back(i);
	}
	for (int i = 0; i < m; i++)
	{
		int f, e, m;
		cin >> f >> e >> m;
		rotate(v.begin() + f, v.begin() + m, v.begin() + e + 1);
	}
	for (auto it = v.begin() + 1; it != v.end(); it++)
	{
		cout << *it << ' ';
	}
	return 0;
}