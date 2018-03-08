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
	for (char c = 'a' ; c <= 'z'; c++)
	{
		cout << count(s.begin(), s.end(), c) << ' ';
	}
	
	return 0;
}