#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n, m;
	vector<int> v;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		v.push_back(m);
	}

	cin >> n;
	cout << count(v.begin(), v.end(), n) << '\n';
	return 0;
}