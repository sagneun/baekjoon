#include<bitset>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int m, x;
	bitset<20> S;
	string str;

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> str;
		if (str == "add")
		{
			cin >> x;
			S.set(x - 1, true);
		}
		else if (str == "remove")
		{
			cin >> x;
			S.set(x - 1, false);
		}
		else if (str == "check")
		{
			cin >> x;
			printf("%d\n",S.test(x - 1));
		}
		else if (str == "toggle")
		{
			cin >> x;
			S.flip(x - 1);
		}
		else if (str == "all")
		{
			S.set();
		}
		else if (str == "empty")
		{
			S.reset();
		}
	}
	return 0;
}