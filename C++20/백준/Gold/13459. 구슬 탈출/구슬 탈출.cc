#include<bits/stdc++.h>

using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))
#define INF 1e9

enum STATUS
{
	SUCCESS,
	FAILED,
	RUNNING,
	BLOCKED,
	BLOCKED_BY_BALL
};

struct coord
{
	int x, y;
	void operator+=(const coord& other)
	{
		x += other.x;
		y += other.y;
	}
	void operator-=(const coord& other)
	{
		x -= other.x;
		y -= other.y;
	}
	bool operator==(coord other)
	{
		return x == other.x && y == other.y;
	}
};

struct mapInfo
{
	coord red, blue;
	int cnt;
};

int n, m;

int dirX[4]{ 0,0,1,-1 };
int dirY[4]{ 1,-1,0,0 };

bool visited[11][11][11][11];
char c_map[11][11];

coord red, blue, goal;

bool isOn(coord& coord, char c)
{
	return c_map[coord.y][coord.x] == c;
}

STATUS moveRedBall(mapInfo& info, coord& dir)
{
	if (info.red.x == -1)
		return SUCCESS;
	info.red += dir;
	if (isOn(info.red, 'O'))
	{
		info.red = { -1,-1 };
		return SUCCESS;
	}
	if (isOn(info.red, '#'))
	{
		info.red -= dir;
		return BLOCKED;
	}
	if (info.red == info.blue)
	{
		info.red -= dir;
		return BLOCKED_BY_BALL;
	}
	return RUNNING;
}
STATUS moveBlueBall(mapInfo& info, coord& dir)
{
	info.blue += dir;
	if (isOn(info.blue, 'O'))
		return FAILED;
	if (isOn(info.blue, '#'))
	{
		info.blue -= dir;
		return BLOCKED;
	}
	if (info.red == info.blue)
	{
		info.blue -= dir;
		return BLOCKED_BY_BALL;
	}
	return RUNNING;
}

STATUS tiltMap(mapInfo& info, int dir)
{
	coord dirC{ dirX[dir], dirY[dir] };
	info.cnt++;
	while (true)
	{
		STATUS red = moveRedBall(info, dirC);
		STATUS blue = moveBlueBall(info, dirC);
		if (blue == FAILED)
			return FAILED;
		if ((red == BLOCKED && blue == BLOCKED) || (red == BLOCKED_BY_BALL && blue == BLOCKED) || (red == BLOCKED && blue == BLOCKED_BY_BALL))
			break;
		if (red == SUCCESS && blue == BLOCKED)
			return SUCCESS;
	}
	if (visited[info.red.y][info.red.x][info.blue.y][info.blue.x])
		return FAILED;
	visited[info.red.y][info.red.x][info.blue.y][info.blue.x] = true;
	return RUNNING;
}

int main()
{
	MEMSET(visited, false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c_map[i][j];
			if (c_map[i][j] == 'O')
				goal = { j,i };
			else if (c_map[i][j] == 'R')
				red = { j,i };
			else if (c_map[i][j] == 'B')
				blue = { j,i };
		}
	}

	mapInfo first = { red, blue, 0 };

	queue<mapInfo> mapQueue;
	mapQueue.push(first);
	while (!mapQueue.empty())
	{
		mapInfo info = mapQueue.front();
		if (info.cnt >= 10)
			break;
		mapQueue.pop();
		for (int i = 0; i < 4; i++)
		{
			mapInfo copied = info;
			STATUS status = tiltMap(copied, i);
			if (status == FAILED)
				continue;
			if (status == SUCCESS)
			{
				cout << 1;
				return 0;
			}
			if (status == RUNNING)
			{
				mapQueue.push(copied);
			}
		}
	}
	cout << 0;
}