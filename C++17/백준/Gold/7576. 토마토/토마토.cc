#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int tomatoes[1001][1001];
int visited[1001][1001];
int main()
{
	memset(visited, 0, sizeof(visited));
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };

	int width, height;
	cin >> width >> height;

	int count = 0;
	int temp = 0;
	int dayCount = 0;
	int dayDiff = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> tomatoes[i][j];
			if (tomatoes[i][j] == 1)
			{
				q.push({ j,i }); // 토마토 익었으면 일단 탐색 목록에 추가
				visited[i][j] = 1;
				dayDiff++;
			}
		}
	}
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int sx = cx + dx[i];
			int sy = cy + dy[i];
			if (sx < 0 || sy < 0 || sx >= width || sy >= height) continue;
			if (tomatoes[sy][sx] == 0)
			{
				visited[sy][sx] = 1;
				tomatoes[sy][sx] = 1;
				temp++;
				q.push({ sx,sy });
			}
		}
		dayCount++;
		if (dayCount == dayDiff)
		{
			dayCount = 0;
			dayDiff = temp;
			temp = 0;
			count++;
		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (visited[i][j] == 0 && tomatoes[i][j] != -1)
			{	
				cout << -1;
				return 0;
			}
		}
	}

	cout << count - 1;
}