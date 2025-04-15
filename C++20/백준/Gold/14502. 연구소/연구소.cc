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
using std::pair;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))
#define MEMCPY(to, arr) memcpy(to, arr, sizeof(arr))

int n, m;
int max = 0;
int copiedMap[9][9];
int map[9][9];
vector<pair<int, int>> emptySpaceVec;
vector<pair<int, int>> virusVec;
bool visited[9][9];
int dirX[4]{ 1,-1,0,0 };
int dirY[4]{ 0,0,1,-1 };

void placeWall(int x, int y)
{
	map[y][x] = 1;
}

void unplaceWall(int x, int y)
{
	map[y][x] = 0;
}

void spreadVirus(int x, int y)
{
	queue<pair<int, int>> virusQueue;
	virusQueue.push({ x,y });

	while (!virusQueue.empty())
	{
		int curX = virusQueue.front().first;
		int curY = virusQueue.front().second;

		virusQueue.pop();

		for (int i = 0; i < 4; i++)
		{
			int dx = curX + dirX[i];
			int dy = curY + dirY[i];
			if (dx < 0 || dy < 0 || dx >= m || dy >= n || visited[dy][dx] || copiedMap[dy][dx] == 1)
				continue;
			visited[dy][dx] = true;
			copiedMap[dy][dx] = 2;
			virusQueue.push({ dx,dy });
		}
	}
}

int countingSafeZone()
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (copiedMap[i][j] == 0)
				sum++;
		}
	}
	return sum;
}

void placing(int wallCnt)
{
	if (wallCnt == 3)
	{
		MEMSET(visited, false);
		MEMCPY(copiedMap, map);

		for (auto& pair : virusVec)
		{
			if (!visited[pair.second][pair.first])
				spreadVirus(pair.first, pair.second);
		}
		int sum = countingSafeZone();
		max = std::max(sum, max);
		return;
	}

	for (auto& pair : emptySpaceVec)
	{
		if (map[pair.second][pair.first] == 1)
			continue;
		placeWall(pair.first, pair.second);
		placing(wallCnt + 1);
		unplaceWall(pair.first, pair.second);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
				emptySpaceVec.push_back({ j,i });
			else if (map[i][j] == 2)
				virusVec.push_back({ j,i });
		}
	}

	placing(0);
	cout << max;
}