#include<iostream>
#include<string>
using namespace std;
int broken[10];
int now = 100;

int ispossible(int v)
{
	int len = 0;

	if (v == 0)
	{
		if (broken[0] == true)
		{
			return -1;
		}
		return 1;
	}
	else
	{
		while (v > 0)
		{
			int check = v % 10;
			len++;
			v = v / 10;
			if (broken[check] == true)
			{
				return -1;
			}
		}
		return len;
	}
}
int countToChangeChannel(int n)
{
	if (n == now)
	{
		return 0;
	}
	else
	{
		int cnt = abs(now - n); // 100���� �׳� +�� -�� ������
		int min = 1000000;
		int len;

		for (int i = 0; i <= 1000000; i++)
		{
			len = ispossible(i);
			if (len != -1)
			{
				if (i == n)
				{
					if (min > len)
					{
						return len;
					}
				}
				else
				{
					len = abs(n - i) + len;
					if (min > len)
					{
						min = len;
					}
				}
			}
		}

		if (min < cnt)
		{
			return min;
		}
		else {
			return cnt;
		}
	}
}
int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int v;
		cin >> v;
		broken[v] = true;
	}
	printf("%d", countToChangeChannel(n));
	return 0;
}


//----------------------------Baekjoon explanation
/*#include <iostream>
using namespace std;
bool broken[10]; // ��ư�� ������ ������ true, �ƴϸ� false
int possible(int c) {
    if (c == 0) {
        if (broken[0]) {
            return 0;
        } else {
            return 1;
        }
    }
    int len = 0;
    while (c > 0) {
        if (broken[c % 10]) {
            return 0;
        }
        len += 1;
        c /= 10;
    }
    return len;
}
int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        broken[x] = true;
    }
    int ans = n - 100; // n >= 100
    if (ans < 0) {
        ans = -ans; // n < 100
    }
    for (int i = 0; i <= 1000000; i++) { // ���� ��ư���� �̵��ϴ� ä��
        int c = i;
        int len = possible(c); // ���̸� ���.
        if (len > 0) {
            int press = c - n; // +�� -�� �� �� ������ �ϴ��� ���
            if (press < 0) {
                press = -press; // +�� ������ ���
            }
            if (ans > len + press) {
                ans = len + press;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
	}*/