#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> v;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		v.push_back(m);
	}

	pair<vector<int>::iterator, vector<int>::iterator> result = minmax_element(v.begin(), v.end());

	cout << *result.first << ' ' << *result.second << '\n';

	return 0;
}