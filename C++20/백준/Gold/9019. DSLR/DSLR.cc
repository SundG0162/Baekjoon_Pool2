#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<map>
#include<unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::stack;
using std::string;

bool visited[10001];

int getD(int n)
{
	return (n * 2) % 10000;
}

int getS(int n)
{
	return (n - 1) < 0 ? 9999 : n - 1;
}

int getL(int n)
{
	int l = n;
	int div = l / 1000;
	l *= 10;
	l -= div * 10000;
	l += div;
	return l;
}

int getR(int n)
{
	int r = n;
	int mod = r % 10;
	r /= 10;
	r += mod * 1000;
	return r;
}

void bfs()
{
	memset(visited, false, sizeof(visited));

	int a, dest;
	cin >> a >> dest;

	queue<std::pair<int, string>> q;
	q.push({ a, "" });

	while (!q.empty())
	{
		int cur = q.front().first;
		string cmd = q.front().second;
		cmd.reserve(100001);
		q.pop();

		int next[4] = { getD(cur), getS(cur), getL(cur), getR(cur) };
		char op[4] = { 'D', 'S', 'L', 'R' };

		for (int i = 0; i < 4; i++)
		{
			int cur = next[i];

			if (cur == dest)
			{
				cout << cmd + op[i] << "\n";
				return;
			}

			if (!visited[cur])
			{
				visited[cur] = true;
				q.push({ cur, cmd + op[i] });
			}
		}
	}
}

int main()
{

	int t;
	cin >> t;

	while (t--)
	{
		bfs();
	}
}