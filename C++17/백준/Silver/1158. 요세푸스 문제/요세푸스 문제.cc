#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	cout << "<";
	while (true)
	{
		for (int i = 0; i < k - 1; i++)
		{
			int x = q.front();
			q.pop();
			q.push(x);
		}
		cout << q.front();
		q.pop();
		if (q.empty())
		{
			break;
		}
		else
		{
			cout << ", ";
		}
	}
	cout << ">";
}