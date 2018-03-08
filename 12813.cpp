#include<iomanip>
#include<iostream>
#include<bitset>
#include<string>
using namespace std;
int main()
{
	string a, b;
	cin >> a >> b;

	bitset<100000> a_b(a);
	bitset<100000> b_b(b);

	cout << (a_b&b_b) << '\n';
	cout << (a_b|b_b) << '\n';
	cout << (a_b^b_b) << '\n';
	cout << ~(a_b) << '\n';
	cout << ~(b_b) << '\n';
	return 0;
}