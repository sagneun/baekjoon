#include<iomanip>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;

	while (getline(cin, s))
	{
		int lower = 0, upper = 0, number = 0, space = 0;
		for (char c : s)
		{
			if (c >= 'a' && c <= 'z')
			{
				lower++;
			}
			else if (c >= 'A' && c <= 'Z')
			{
				upper++;
			}
			else if (c >= '0' && c <= '9')
			{
				number++;
			}
			else if (c == ' ')
			{
				space++;
			}
		}

		cout << lower << ' ' << upper << ' ' << number << ' ' << space << '\n';
	}

	return 0;
}