#include<iomanip>
#include<iostream>
#include<vector>
#include<functional>
using namespace std;
int main()
{
	int n1, n2;
	std::vector<function<int(int, int)>>	d; // �����Լ� ����!!!

	cin >> n1 >> n2;

	d.push_back([](int x, int y) {
		return x + y;
	});
	d.push_back([](int x, int y) {
		return x * y;
	});
	d.push_back([](int x, int y) {
		return x / y;
	});
	d.push_back([](int x, int y) {
		return x - y;
	});

	for (auto x : d) {
		cout << x(n1, n2) << '\n';
	}
	return 0;
}