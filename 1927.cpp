#include<iomanip>
#include<iostream>
#include<list>
#include<queue>
#include<functional>
using namespace std;
int main()
{
	int n, x;
	priority_queue<int, vector<int>, greater<int>> p;
	vector<int> result;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x == 0)
		{
			if (p.empty())
			{
				result.push_back(0);
			}
			else
			{
				result.push_back(p.top());
				p.pop();
			}
		}
		else {
			p.push(x);
		}
	}

	for (int a : result)
	{
		cout << a << '\n';
	}
	return 0;
}