#include<iomanip>
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	std::ios_base::sync_with_stdio(false);
	map<string, int> color = {
		{"black", 0}, {"brown", 1}, {"red", 2},
		{"orange", 3}, {"yellow", 4}, {"green", 5},
		{"blue", 6}, {"violet", 7}, {"grey", 8},
		{"white", 9}
	};
	
	string a, b, c;
	cin >> a >> b >> c;

	long long ans = (long long)(color[a] * 10 + color[b]);
	for (int i = 0; i < color[c]; i++)
	{
		ans = ans * 10LL;
	}
	cout << ans;
	return 0;
}