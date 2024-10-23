#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	if (c % 2 == 0)
	{
		cout << a;
	}
	else
	{
		cout << (a ^ b);
	}
}