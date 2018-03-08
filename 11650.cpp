#include<iomanip>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int n, x, y;
	vector<pair<int, int>> v; // pair���� ���Ҷ��� first, seconde �񱳼����� return�� �ϱ� ������ �켱������ �������� first�� �ΰ� ���ϸ� ����

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
		return a < b;
	});

	for (auto x : v)
	{
		cout << x.first << ' ' << x.second << '\n';
	}
	return 0;
}