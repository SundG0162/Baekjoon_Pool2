#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int n;
string map[101];
bool visited[101][101];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int bfs(int x, int y)
{
	if (visited[y][x])
		return 0;
	queue<pair<int, int>> q;
	char myRegion = map[y][x];

	q.push({ x,y });
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int sx = cx + dx[i];
			int sy = cy + dy[i];
			if (sx < 0 || sy < 0 || sx >= n || sy >= n) continue;
			if (map[sy][sx] == myRegion && !visited[sy][sx])
			{
				q.push({ sx,sy });
				visited[sy][sx] = true;
			}
		}
	}
	return 1;
}

int bfsCr(int x, int y)
{
	if (visited[y][x])
		return 0;
	queue<pair<int, int>> q;
	char myRegion = map[y][x];

	q.push({ x,y });
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int sx = cx + dx[i];
			int sy = cy + dy[i];
			if (sx < 0 || sy < 0 || sx >= n || sy >= n) continue;
			if ((map[sy][sx] == myRegion || map[sy][sx] == (myRegion == 'R' ? 'G' : myRegion == 'G' ? 'R' : 'F')) && !visited[sy][sx])
			{
				q.push({ sx,sy });
				visited[sy][sx] = true;
			}
		}
	}
	return 1;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(visited, false, sizeof(visited));
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}

	int cnt = 0, cntCr = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cnt += bfs(j, i);
		}
	}
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cntCr += bfsCr(j, i);
		}
	}
	cout << cnt << '\n' << cntCr;
}