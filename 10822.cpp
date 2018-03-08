#include<iomanip>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	int sum = 0;
	string toSum = "";
	/*while (getline(cin, s))
	{
		for (char c : s)
		{
			if (c >= '0' && c <= '9')
			{
				toSum.push_back(c);
			}
			else if (c == ',')
			{
				sum += stoi(toSum);
				toSum = "";
			}
		}
		sum += stoi(toSum);
		cout << sum << '\n';
	}*/

	while (getline(cin, toSum, ','))
	{
		sum += stoi(toSum);
	}
	cout << sum << '\n';
	return 0;
}