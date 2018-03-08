#include<iomanip>
#include<iostream>
#include<set>
using namespace std;
int main()
{
	int N,v;
	cin >> N;

	set<int> s;

	for (int i = 0; i < N; i++)
	{
		cin >> v;
		s.insert(v);
	}

	for (auto x : s)
	{
		cout << x << ' ';
	}

	return 0;
}