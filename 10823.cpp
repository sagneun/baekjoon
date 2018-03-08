#include<iomanip>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	string s;
	string line;
	while (cin >> line)
	{
		s += line;
	}
	istringstream sin(s); // istringstream으로 선언해주면 cin처럼 표준 입출력 변수로 사용 가능하다 => 파싱할때 사용하기
	string number;
	int sum = 0;
	while (getline(sin, number, ','))
	{
		sum += stoi(number);
	}
	cout << sum << '\n';
	return 0;
}