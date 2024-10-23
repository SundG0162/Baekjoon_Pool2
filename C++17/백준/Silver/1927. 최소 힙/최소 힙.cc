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

	priority_queue<int, vector<int>, greater<int>> q;
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x == 0)
		{
			if (q.empty())
			{
				cout << 0 << '\n';
				continue;
			}
			cout << q.top() << '\n';
			q.pop();
		}
		else
		{
			q.push(x);
		}
	}
}