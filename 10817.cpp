#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int a, b, c;
	vector<int> v;
	cin >> a >> b >> c;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);

	auto maxE = max_element(v.begin(), v.end());
	v.erase(maxE);
	maxE = max_element(v.begin(), v.end());

	cout << *maxE << '\n';
	return 0;
}