#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<deque>
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
using std::deque;
using std::stack;
using std::string;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

int height, width;

int dirX[4]{ 0,0,1,-1 };
int dirY[4]{ 1,-1,0,0 };

// 0 = 방문하지 않음
// 1 = 방문했고 닫힌 구멍
// 2 = 방문했고 열린 구멍
// 3 = 방문한 치즈
int visited[101][101];
int map[101][101];

int lastCnt = 0;
int curCnt = 0;
int hours = 0;

bool isOpenedHole(int x, int y)
{
	if (visited[y][x] == 1)
		return false;
	else if (visited[y][x] == 2)
		return true;
	//0이면 이제 탐색해야함.
	vector<std::pair<int, int>> visitedCoord;
	queue<std::pair<int, int>> holeQueue;
	holeQueue.push({ x,y });
	bool isOpened = false;
	while (!holeQueue.empty())
	{
		int curX = holeQueue.front().first;
		int curY = holeQueue.front().second;
		holeQueue.pop();

		for (int i = 0; i < 4; i++)
		{
			int dx = curX + dirX[i];
			int dy = curY + dirY[i];
			if (dx < 0 || dy < 0 || dx >= width || dy >= height)
			{
				isOpened = true;
				continue;
			}
			if (map[dy][dx] == 0 && !visited[dy][dx])
			{
				visited[dy][dx] = 1;
				holeQueue.push({ dx,dy });
				visitedCoord.push_back({ dx,dy });
			}
		}
	}
	if (isOpened)
	{
		for (auto& coord : visitedCoord)
		{
			visited[coord.second][coord.first] = 2;
		}
	}
	return isOpened;
}

void bfs(int x, int y)
{
	if (visited[y][x])
		return;
	queue<std::pair<int, int>> chessQueue;
	chessQueue.push({ x,y });
	while (!chessQueue.empty())
	{
		int curX = chessQueue.front().first;
		int curY = chessQueue.front().second;
		chessQueue.pop();
		int cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			int dx = curX + dirX[i];
			int dy = curY + dirY[i];
			if (dx < 0 || dy < 0 || dx >= width || dy >= height)
				continue;

			if (map[dy][dx] == 0)
			{
				if (isOpenedHole(dx, dy))
					cnt++;
			}
			else if (map[dy][dx] == 1)
			{
				if (visited[dy][dx] != 3)
				{
					visited[dy][dx] = 3;
					chessQueue.push({ dx,dy });
				}
			}
		}
		if(cnt >= 2)
			map[curY][curX] = 2;
	}
}

void solve()
{
	while (true)
	{
		MEMSET(visited, 0);
		curCnt = 0;
		hours++;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (map[i][j] == 0)
					continue;
				bfs(j, i);
			}
		}
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (map[i][j] == 2)
				{
					curCnt++;
					map[i][j] = 0;
				}
			}
		}
		if (curCnt == 0)
		{
			cout << hours - 1;
			break;
		}
		lastCnt = curCnt;
	}
}

int main()
{
	cin >> height >> width;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> map[i][j];
		}
	}

	solve();
}