#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;

int visited[100001];
int n, k;

void bfs()
{
	queue<int> q;
	q.push(n);
	visited[n] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (x == k)
			return;


		int movements[3] = { x + 1, x - 1, x * 2 };

		for (int i = 0; i < 3; i++)
		{
			int move = movements[i];
			if (move < 0 || move >= 100001)
				continue;
			if (visited[move] == -1 || visited[move] > visited[x] + 1)
			{
				visited[move] = visited[x] + 1;
				q.push(move);
			}
		}
	}
}

int main()
{
	memset(visited, -1, sizeof(visited));
	cin >> n >> k;
	bfs();
	cout << visited[k];
}