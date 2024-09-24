#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int testcase, n, m, num, x, y;
int board[51][51];
bool visited[51][51];

void DFS(int y, int x)
{
	visited[y][x] = true;
	int dx[4]{ 0,0,-1,1 };
	int dy[4]{ -1,1,0,0 };
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (!visited[ny][nx] && board[ny][nx] == 1)
		{
			DFS(ny, nx);
		}
	}
}

int main()
{
	cin >> testcase;
	while (testcase--)
	{
		memset(board, 0, sizeof(board));
		memset(visited, false, sizeof(visited));
		int cnt = 0;
		cin >> m >> n >> num;
		for (int i = 0; i < num; i++)
		{
			cin >> x >> y;
			board[y][x] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 1 && !visited[i][j])
				{
					DFS(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}
