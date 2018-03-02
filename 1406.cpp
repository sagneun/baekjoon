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

		if (c == 'L') // Ŀ�� ���� �̵�
		{
			if (cursor != editor.begin())
			{
				--cursor;
			}
		}
		else if (c == 'D') // Ŀ�� ������ �̵�
		{
			if (cursor != editor.end())
			{
				++cursor;
			}
		}
		else if (c == 'B') // Ŀ�� ���� ����
		{
			if (cursor != editor.begin())
			{
				cursor = editor.erase(--cursor);
			}
		}
		else if (c == 'P') // Ŀ���� ���ʿ� �߰�
		{
			cin >> v;
			cursor = editor.insert(cursor, v);
			++cursor;

		}
	}
	showEditor(editor);
	return 0;
}