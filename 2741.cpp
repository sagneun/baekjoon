#include<iomanip>
#include<iostream>
using namespace std;
int main()
{
	int n;
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << '\n';
	}

	return 0;
}