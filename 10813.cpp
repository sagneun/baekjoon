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
		int n1,n2;
		cin >> n1 >> n2;
		swap(v[n1],v[n2]);
	}
	for (auto it = v.begin() + 1; it != v.end(); it++)
	{
		cout << *it << ' ';
	}
	return 0;
}