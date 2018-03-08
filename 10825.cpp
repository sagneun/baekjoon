#include<iomanip>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<tuple>
using namespace std;
int main()
{
	int n;
	string name; int kor_scor, eng_scor, math_scor;
	vector<tuple<string, int, int, int>> v;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> kor_scor >> eng_scor >> math_scor;
		v.push_back(make_tuple(name, kor_scor, eng_scor, math_scor));
	}
	
	sort(v.begin(), v.end(), [](tuple<string, int, int, int> a, tuple<string, int, int, int> b) {
		if (get<1>(a) == get<1>(b))
		{
			if (get<2>(a) == get<2>(b))
			{
				if (get<3>(a) == get<3>(b))
				{
					return get<0>(a) < get<0>(b);
				}
				else {
					return get<3>(a) > get<3>(b);
				}
			}
			else {
				return get<2>(a) < get<2>(b);
			}
		}
		else {
			return get<1>(a) > get<1>(b);
		}
	});

	for (auto x : v)
	{
		cout << get<0>(x) << '\n';
	}
	return 0;
}