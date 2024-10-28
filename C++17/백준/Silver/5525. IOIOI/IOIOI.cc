#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int map[501][501];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, a;
	string g = "";
	string str;
	cin >> n >> a >> str;

	for (int i = 0; i < 2 * n + 1; i++)
	{
		if (i % 2 == 0)
		{
			g += 'I';
		}
		else
		{
			g += 'O';
		}
	}

	int count = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'O') continue;
		string a = str.substr(i, 2 * n + 1);
		if (a == g)
		{
			count++;
		}
	}
	cout << count;
}