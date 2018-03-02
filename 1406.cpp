#include<iomanip>
#include<iostream>
#include<list>
#include<string>

using namespace std;

void showEditor(list<char> editor)
{
	auto it = editor.begin();

	for (it = editor.begin(); it != editor.end(); it++)
	{
		cout << *it;
	}
	cout << '\n';
	return;
}
int main()
{
	string s;
	cin >> s;
	list<char> editor(s.begin(), s.end());
	auto cursor = editor.end();

	int n; char c, v;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> c;

		if (c == 'L') // 커서 왼쪽 이동
		{
			if (cursor != editor.begin())
			{
				--cursor;
			}
		}
		else if (c == 'D') // 커서 오른쪽 이동
		{
			if (cursor != editor.end())
			{
				++cursor;
			}
		}
		else if (c == 'B') // 커서 왼쪽 삭제
		{
			if (cursor != editor.begin())
			{
				cursor = editor.erase(--cursor);
			}
		}
		else if (c == 'P') // 커서의 왼쪽에 추가
		{
			cin >> v;
			cursor = editor.insert(cursor, v);
			++cursor;

		}
	}
	showEditor(editor);
	return 0;
}