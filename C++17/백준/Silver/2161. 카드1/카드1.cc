#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;


int main()
{
	int n;
	cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	while (true)
	{
		int x = q.front();
		cout << x << " ";
		q.pop();
		if (q.empty())
			break;
		int y = q.front();
		q.pop();
		q.push(y);
	}
}