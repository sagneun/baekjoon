#include<iomanip>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	vector<int> v;

	cin >> s;
	for (char c = 'a'; c <= 'z'; c++)
	{
		auto it = find(s.begin(), s.end(), c);
		int location = -1;
		if(it != s.end()) // 있는 경우
		{
			location = it - s.begin();
		}
		cout << location << ' ';
	}

	return 0;
}