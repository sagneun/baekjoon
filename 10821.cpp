#include<iomanip>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;

	while (getline(cin, s))
	{
		int cnt = 0;
		char recent = ',';
		for (char c : s)
		{
			if (recent == ',' && c != ',')
			{
				cnt++;
			}

			recent = c;
		}

		cout << cnt << '\n';
	}
	/*
	while(getline(cin, s, ',')){
		cnt++;
	}
	*/
	return 0;
}