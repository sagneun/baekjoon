#include<iomanip>
#include<iostream>
#include<list>
#include<vector>
/*
���ʹ�! erase�� �ϰ� ���� iterator ��� �ȵ�, vector �� random access iterator possible
����Ʈ��! iterator�� ++/--�� ������ ������ �ȵ�, list��					''	impossible
*/
using namespace std;
int main()
{
	int n, v, location, move;
	list<pair<int, int>> balloon;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> v;
		balloon.push_back({ i,v });
	}
	auto it = balloon.begin();
	auto rm_it = balloon.begin();
	auto end = --balloon.end();
	while (1)
	{
		rm_it = it;
		int location = rm_it->first;
		int move = rm_it->second;

		cout << (*rm_it).first << ' ';

		if (rm_it == end)
		{
			it = balloon.begin();
			balloon.erase(rm_it);
		}
		else
		{
			it = balloon.erase(rm_it);
		}

		if (balloon.empty() == 1)
		{
			break;
		}
		end = balloon.end();
		--end;

		if (move < 0) { // move to left
			for (int i = 1; i <= abs(move); i++)
			{
				if (it == balloon.begin())
				{
					it = end;
				}
				else {
					--it;
				}
			}
		}
		else if (move >= 0)// move to right
		{
			for (int i = 1; i <= move - 1; i++)
			{
				if (it == end)
				{
					it = balloon.begin();
				}
				else {
					++it;
				}
			}
		}

	}
	return 0;
}