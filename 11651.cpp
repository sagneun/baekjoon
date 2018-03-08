#include<iomanip>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int n, x, y;
	vector<pair<int, int>> v; // pair끼리 비교할때는 first, seconde 비교순으로 return을 하기 때문에 우선순위가 높은것은 first에 두고 비교하면 간단

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second)
		{
			return a.first < b.first;
		}
		else {
			return a.second < b.second;
		}
	});

	for (auto x : v)
	{
		cout << x.first << ' ' << x.second << '\n';
	}
	return 0;
}