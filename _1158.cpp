#include<iomanip>
#include<iostream>
#include<list>
using namespace std;
int main()
{
	int n, m, v;
	list<int> l;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		l.push_back(i);
	}
	auto it = l.begin();
	auto rm_it = l.begin();
	auto end = --l.end();
	
	for (int i = 1; i < m; i++) // 시작 위치
	{
		rm_it++;
	}
	//cout << '<';
	while (1)
	{
		cout << *rm_it << ' ';
		
		if (it == end)
		{
			l.erase(rm_it);
			it = l.begin();
		}
		else {
			it = l.erase(rm_it);
		}

		if (l.empty())
		{
			//cout << '>';
			break;
		}
		else {
			//cout << ", ";
		}
		end = --l.end();
		for (int i = 1; i < m; i++)
		{
			if (it == end)
			{
				it = l.begin();
			}
			else {
				it++;
			}
		}
		rm_it = it;
	}

	return 0;
}