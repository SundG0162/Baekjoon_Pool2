#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int width, height;

int map[1001][1001];
int visited[1001][1001];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void bfs(int x, int y)
{
	memset(visited, -1, sizeof(visited));
	queue<pair<int, int>> q;
	visited[y][x] = 0;
	q.push({ x,y });

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= width || ny >= height) continue;

			if (visited[ny][nx] == -1)
			{
				if (map[ny][nx] == 0)
				{
					visited[ny][nx] = -2;
					continue;
				}
				visited[ny][nx] = visited[cy][cx] + 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main()
{
	cin >> height >> width;
	int sx, sy;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				sx = j;
				sy = i;
			}
		}
	}

	bfs(sx, sy);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if(map[i][j] == 0)
				cout << 0 << ' ';
			else if(visited[i][j] == -1)
				cout << -1 << ' ';
			else
				cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
}