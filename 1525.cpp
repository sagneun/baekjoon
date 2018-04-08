#include<iostream>
#include<map>
#include<string>
#include<queue>
using namespace std;

int d[362880];// 9 factorial value = 362880

queue<int> que;
map<int, int> m;

void BFS(int from, int to = 123456789)
{
	string next; int now, swt = 0, nine, cnt = 0;
	int x, y, nidx;
	m.insert({ from, cnt });
	auto it = m.find(from);
	d[it->second] = 0;
	que.push(from);
	cnt++;

	while (!que.empty())
	{
		now =  que.front(); que.pop();
		next = to_string(now);
		
		if (swt != 1)
		{
			if (now == to)
			{
				swt = 1;
				printf("%d", d[m.find(now)->second]);
			}
			else
			{
				nine = next.find('9');
				x = nine / 3; y = nine % 3;
				if (x > 0) // ╩С
				{
					nidx = (x - 1) * 3 + y;
					next[nine] = next[nidx]; next[nidx] = '9';
					if (m.find(stoi(next)) == m.end())
					{
						m.insert({ stoi(next),cnt });
						que.push(stoi(next));
						d[cnt] = d[m.find(now)->second] + 1;
						cnt++;
					}
					next = to_string(now);
				}
				if (x < 2) // го
				{
					nidx = (x + 1) * 3 + y;
					next[nine] = next[nidx]; next[nidx] = '9';
					if (m.find(stoi(next)) == m.end())
					{
						m.insert({ stoi(next),cnt });
						que.push(stoi(next));
						d[cnt] = d[m.find(now)->second] + 1;
						cnt++;
					}
					next = to_string(now);
				}
				if (y > 0) // аб
				{
					nidx = x * 3 + y - 1;
					next[nine] = next[nidx]; next[nidx] = '9';
					if (m.find(stoi(next)) == m.end())
					{
						m.insert({ stoi(next),cnt });
						que.push(stoi(next));
						d[cnt] = d[m.find(now)->second] + 1;
						cnt++;
					}
					next = to_string(now);
				}
				if (y < 2) // ©Л
				{
					nidx = x * 3 + y + 1;
					next[nine] = next[nidx]; next[nidx] = '9';
					if (m.find(stoi(next)) == m.end())
					{
						m.insert({ stoi(next),cnt });
						que.push(stoi(next));
						d[cnt] = d[m.find(now)->second] + 1;
						cnt++;
					}
				}
			}
		}
	}
	if (swt == 0)
	{
		printf("-1");
	}
}
int main()
{
	int from = 0;
	int v, pv = 100000000;
	for (int i = 0; i < 9; i++)
	{
		cin >> v;
		if (v == 0)
		{
			v = 9;
		}
		from += v*pv;
		pv = pv / 10;
	}

	BFS(from);
	return 0;
}