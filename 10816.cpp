#include<iomanip>
#include<iostream>
#include<set>
#include<stdio.h>
using namespace std;
// scanf/printf가 cout/cin보다 빠르다 : 
// set은 [] 사용이 안되기 때문에 random access iterator impossible
// By default the i/o functions cin and cout are meant to synchronise with the library #include<stdio.h>.This makes them slow.You can change this by adding the following line below the int main() line of your function "std::ios_base::sync_with_stdio(false);"

int main()
{
	int n, m, v;
	scanf("%d", &n);
	multiset<int> sanggeunCard;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &v);
		sanggeunCard.insert(v);
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &v);
		printf("%d ", sanggeunCard.count(v));
	}

	return 0;
}