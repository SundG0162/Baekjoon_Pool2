#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <cstring>
using namespace std;

int n, m, v;
bool visited[1001];
bool linked[1001][1001]{ {false} };

void BFS(int v)
{
	queue<int> q;
	q.push(v);
	visited[v] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << " ";
		for (int i = 1; i <= n; i++)
		{
			if (linked[x][i] && !visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

void DFS(int v)
{
	visited[v] = true;
	cout << v << " ";
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i] && linked[v][i])
		{
			DFS(i);
		}
	}
}

int main()
{
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		linked[a][b] = true;
		linked[b][a] = true;
	}
	DFS(v);
	cout << '\n';
	memset(visited, false, sizeof(visited));
	BFS(v);
	return 0;
}