#include<iomanip>
#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;
int main()
{
	int n, v;
	queue<int> q;
	vector<int> result;
	string cmd;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> cmd;
		if (cmd == "push")
		{
			cin >> v;
			q.push(v);
		}
		else if (cmd == "pop")
		{
			if (q.empty())
			{
				v = -1;
			}
			else {
				v = q.front();
				q.pop();
			}
			result.push_back(v);
		}
		else if (cmd == "front")
		{
			if (q.empty())
			{
				v = -1;
			}
			else {
				v = q.front();
			}
			result.push_back(v);
		}
		else if (cmd == "back")
		{
			if (q.empty())
			{
				v = -1;
			}
			else {
				v = q.back();
			}
			result.push_back(v);
		}
		else if (cmd == "size")
		{
			result.push_back(q.size());
		}
		else if (cmd == "empty")
		{
			result.push_back(q.empty());
		}
	}

	for (int x : result)
	{
		cout << x << '\n';
	}
	return 0;
}