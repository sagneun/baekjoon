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
		int cnt = abs(now - n); // 100에서 그냥 +나 -를 누를때
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
bool broken[10]; // 버튼이 망가져 있으면 true, 아니면 false
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
    for (int i = 0; i <= 1000000; i++) { // 숫자 버튼으로 이동하는 채널
        int c = i;
        int len = possible(c); // 길이를 잰다.
        if (len > 0) {
            int press = c - n; // +나 -를 몇 번 눌러야 하는지 계산
            if (press < 0) {
                press = -press; // +를 누르는 경우
            }
            if (ans > len + press) {
                ans = len + press;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
	}*/