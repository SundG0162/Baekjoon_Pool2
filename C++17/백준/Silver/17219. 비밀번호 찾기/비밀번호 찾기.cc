#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	unordered_map<string, string> map;
	int a, b;
	cin >> a >> b;

	for (int i = 0; i < a; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		map.insert({ s1, s2 });
	}

	for (int i = 0; i < b; i++)
	{
		string s;
		cin >> s;
		cout << map[s] << '\n';
	}
}