#include<iomanip>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int n;
	string w;
	vector<string> a;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> w;
		a.push_back(w);
	}

	sort(a.begin(), a.end(), [](string u, string v) {
		if (u.size() == v.size())
		{
			return u < v;
		}
		else {
			return u.size() < v.size();
		}
	});

	auto last = unique(a.begin(), a.end());
	a.erase(last, a.end());
	for (string x : a)
	{
		cout << x << '\n';
	}
	return 0;
}