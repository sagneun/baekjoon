#include<iomanip>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	unsigned int a, b, c, d;
	cin >> a >> b >> c >> d;
	string result1 = to_string(a) + to_string(b);
	string result2 = to_string(c) + to_string(d);

	cout << stoi(result1)+stoi(result2);
	return 0;
}
