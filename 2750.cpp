#include<iomanip>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n, m;
	vector<int> a;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		a.push_back(m);
	}
	sort(a.begin(), a.end());
	for (int x : a)
	{
		cout << x << '\n';
	}
	return 0;
}