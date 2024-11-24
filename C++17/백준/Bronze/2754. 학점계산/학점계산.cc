#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	map<string, float> m;
	m.insert({ "A+", 4.3f });
	m.insert({ "A0", 4.0f });
	m.insert({ "A-", 3.7f });
	m.insert({ "B+", 3.3f });
	m.insert({ "B0", 3.0f });
	m.insert({ "B-", 2.7f });
	m.insert({ "C+", 2.3f });
	m.insert({ "C0", 2.0f });
	m.insert({ "C-", 1.7f });
	m.insert({ "D+", 1.3f });
	m.insert({ "D0", 1.0f });
	m.insert({ "D-", 0.7f });
	m.insert({ "F+", 0.0f });
	string str;
	cin >> str;
	cout << fixed;
	cout.precision(1);
	cout << m[str];
}