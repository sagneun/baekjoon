#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool check(string code)
{
	int consonant = 0, vowel = 0;
	for (int i = 0; i < (signed int)code.length() ; i++)
	{
		if (code[i] == 'a' || code[i] == 'e' || code[i] == 'i' || code[i] == 'o' || code[i] == 'u')
		{
			vowel += 1;
		}
		else
		{
			consonant += 1;
		}
	}
	if (vowel > 0 && consonant > 1)
	{
		return true;
	}
	return false;
}
void DFS(int n, string now, string group, int i)
{
	if ((signed int)now.length() == n)
	{
		if (check(now))
		{
			cout << now << "\n";
		}
		return;
	}
	if (i >= group.size())
	{
		return;
	}
	DFS(n, now + group[i], group, i + 1);
	DFS(n, now , group, i + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, c;
	string group = "";
	char v;
	cin >> n >> c;
	
	for (int i = 0; i < c; i++)
	{
		cin >> v;
		group = group + v;
	}
	sort(group.begin(), group.end());

	DFS(n, "", group, 0);
	return 0;
}