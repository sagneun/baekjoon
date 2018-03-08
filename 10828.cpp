#include<iomanip>
#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
int main()
{
	int n, v;
	stack<int> s;
	vector<int> result;
	string cmd;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> cmd;
		if (cmd == "push")
		{
			cin >> v;
			s.push(v);
		}
		else if (cmd == "pop")
		{
			if (s.empty())
			{
				v = -1;
			}
			else {
				v = s.top();
				s.pop();
			}	
			result.push_back(v);
		}
		else if (cmd == "top")
		{
			if (s.empty())
			{
				v = -1;
			}
			else {
				v = s.top();
			}
			result.push_back(v);
		}
		else if (cmd == "size")
		{
			result.push_back(s.size());
		}
		else if (cmd == "empty")
		{
			result.push_back(s.empty());
		}
	}

	for (int x : result)
	{
		cout << x << '\n';
	}
	return 0;
}