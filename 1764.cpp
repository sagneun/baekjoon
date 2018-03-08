#include<iomanip>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<functional>
using namespace std;

int main()
{
	string v;
	int n, m;
	cin >> n >> m;
	set<string> s;
	priority_queue<string, vector<string>, greater<string>> result;

	for (int i = 0; i < n; i++)
	{
		cin >> v;
		s.insert(v);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> v;
		if (!s.insert(v).second)
		{
			result.push(v);
		}
	}

	cout << result.size() << '\n';
	while (!result.empty())
	{
		cout << result.top() << '\n';
		result.pop();
	}
	return 0;
}