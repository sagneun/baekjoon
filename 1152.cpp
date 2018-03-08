#include<iomanip>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int cnt = 0;
	string str;

	while (cin >> str)
	{
		cnt += 1;
	}

	cout << cnt << '\n';
	return 0;
}