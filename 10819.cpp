#include<iomanip>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n, v;
	cin >> n;
	vector<int> ve;
	for (int i = 0; i < n; i++)
	{
		cin >> v;
		ve.push_back(v);
	}
	int maxSum = 0;

	sort(ve.begin(), ve.end());
	do {
		int sum = 0;
		for (auto it = ve.begin(); it != ve.end()-1; it++)
		{
			sum += abs(*it - *(it+1));
		}
		if (maxSum < sum)
		{
			maxSum = sum;
		}
	} while (next_permutation(ve.begin(), ve.end()));
	
	cout << maxSum << '\n';
	return 0;
}