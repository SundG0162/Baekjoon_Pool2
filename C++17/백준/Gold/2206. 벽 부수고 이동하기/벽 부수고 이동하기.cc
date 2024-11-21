#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

int m, n;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int map[1001][1001];
int minDistance[1001][1001];
int visited[1001][1001];

void initMinDistance();
int getMinDistanceW();

int main()
{
	cin >> n >> m;
	string str;
	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = str[j - 1] - '0';
		}
	}


	initMinDistance();
	cout << getMinDistanceW();
}

void initMinDistance()
{
	memset(minDistance, -1, sizeof(minDistance));

	minDistance[n][m] = 0;
	queue<pair<int, int>> q;
	q.push({ m,n });
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = cx + dx[i];
			int ty = cy + dy[i];
			if (tx > m || ty > n || tx < 1 || ty < 1)
				continue;
			if (map[ty][tx] == 0 && (minDistance[ty][tx] == -1 || minDistance[ty][tx] > minDistance[cy][cx] + 1))
			{
				minDistance[ty][tx] = minDistance[cy][cx] + 1;
				q.push({ tx,ty });
			}
		}
	}
}

int getMinDistanceW()
{
	memset(visited, -1, sizeof(visited));
	queue<pair<int, int>> q;
	int minDist = INT32_MAX;
	visited[1][1] = 1;
	q.push({ 1,1 });
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = cx + dx[i];
			int ty = cy + dy[i];
			if (tx > m || ty > n || tx < 1 || ty < 1)
				continue;
			if (map[ty][tx] == 0 && (visited[ty][tx] == -1 || visited[ty][tx] > visited[cy][cx] + 1))
			{
				visited[ty][tx] = visited[cy][cx] + 1;
				q.push({ tx,ty });
			}
			if (map[ty][tx] == 1) // 부수기
			{
				for (int j = 0; j < 4; j++)
				{
					int ex = tx + dx[j];
					int ey = ty + dy[j];
					if (ex > m || ey > n || ex < 1 || ey < 1 || map[ey][ex] == 1 || minDistance[ey][ex] == -1) continue;
					minDist = min(minDist, minDistance[ey][ex] + visited[cy][cx] + 2);
				}
			}
		}
	}
	if (visited[n][m] != -1)
		minDist = min(minDist, visited[n][m]);
	if (minDist == INT32_MAX)
		return -1;
	return minDist;
}
