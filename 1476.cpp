#include<iostream>
using namespace std;
unsigned int theYearOfESM(int e, int s, int m)
{
	int _e, _s, _m, _year;
	for (_year = 1; _year < 8000; _year++)
	{
		_e = _year%15;
		_s = _year%28;
		_m = _year%19;
		
		if (_e == 0)
		{
			_e = 15;
		}
		if (_s == 0)
		{
			_s = 28;
		}
		if (_m == 0)
		{
			_m = 19;
		}

		if (_e == e && _s == s && _m == m)
		{
			return _year;
		}
	}
	return 0;
}
int main()
{
	int e, s, m;
	cin >> e >> s >> m;

	int year = theYearOfESM(e, s, m);
	printf("%ld", year);
	return 0;
}