#include<iomanip>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	vector<pair<int, string>> v;
	int n, age; string name;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> age >> name;
		v.push_back(make_pair(age, name));
	}

	stable_sort(v.begin(), v.end(), [](pair<int, string> a, pair<int, string> b) {
		return a.first < b.first;
	});

	for (auto x : v)
	{
		cout << x.first << ' ' << x.second << '\n';
	}
	return 0;
}