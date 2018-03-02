#include<iomanip>
#include<vector>
#include<iostream>
using namespace std;
// lamda function
int main()
{
	auto print = [] {
		cout << "1/31" << '\n';
	};

	print();
}