#include<iomanip>
#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main()
{
	int n, m, v;
	cin >> n;
	set<int> sanggeunCard;
	vector<int> existCard;

	for (int i = 0; i < n; i++)
	{
		cin >> v;
		sanggeunCard.insert(v);
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> v;
		existCard.push_back(v);
	}

	for (auto x : existCard)
	{
		cout << sanggeunCard.count(x) << ' ';
	}
	return 0;
}