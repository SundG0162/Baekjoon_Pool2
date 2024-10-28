#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int n, m;

bool graph[1001][1001];
bool visited[1001];

int bfs(int v)
{
	if (visited[v])
		return 0;
	queue<int> q;
	q.push(v);
	visited[v] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (graph[x][i] && !visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
	return 1;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += bfs(i);
	}
	cout << sum;
}