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
using std::priority_queue;
using std::queue;
using std::deque;
using std::stack;
using std::string;
using std::pair;
using std::unordered_map;
using std::greater;
using std::less;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))
#define MEMCPY(to, arr) memcpy(to, arr, sizeof(arr))

int n, m, k;
char map[1001][1001];
bool visited[1000][1000][5][28]; // Y, X, 방향, 불상사 개수

struct coord
{
	coord()
	{
		x = -1;
		y = -1;
	}
	coord(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int x, y;
	void operator+=(const coord& other)
	{
		x += other.x;
		y += other.y;
	}
	coord operator+(const coord& other)
	{
		return { x + other.x, y + other.y };
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
	bool isOutOfRange()
	{
		return x < 0 || y < 0 || x >= m || y >= n || map[y][x] == 'X';
	}
};

coord school, home;
coord dir[5] = { { 1,0 }, { 0,1 }, { -1,0 }, { 0,-1 }, { 0,0 } };
int oppositeDir[5] = { 2, 3, 0, 1, 4 };

struct moveInfo
{
	int count = 0;
	int prevDir = 0;
	int misfortune = 0;
	int history[3] = { 0, 0, 0 };
	coord cur;

	bool moveTo(int dirIdx)
	{
		if (dirIdx == oppositeDir[prevDir] && prevDir != 4)
			return false;

		cur += dir[dirIdx];

		if (cur.isOutOfRange())
			return false;

		int latest = 0;
		if (isdigit(map[cur.y][cur.x]))
			latest = map[cur.y][cur.x] - '0';
		int newM = misfortune + latest - history[2];
		if (newM > k)
			return false;
		history[2] = history[1];
		history[1] = history[0];
		history[0] = latest;
		misfortune = newM;
		if (visited[cur.y][cur.x][dirIdx][misfortune])
			return false;
		visited[cur.y][cur.x][dirIdx][misfortune] = true;
		prevDir = dirIdx;
		count++;
		return true;
	}

	bool isFailed()
	{
		return misfortune > k;
	}

	bool isArrived()
	{
		return cur == home;
	}

	coord& getCurrentPos()
	{
		return cur;
	}
};


int main()
{
	cin >> n >> m >> k;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'S')
				school = { j,i };
			else if (map[i][j] == 'H')
				home = { j,i };
		}
	}

	queue<moveInfo> moveQueue;
	moveInfo first;
	first.cur = school;
	first.misfortune = 0;
	first.prevDir = 4;
	moveQueue.push(first);
	while (!moveQueue.empty())
	{
		moveInfo info = moveQueue.front();
		moveQueue.pop();

		for (int i = 0; i < 4; i++)
		{
			moveInfo tempInfo = info;
			if (tempInfo.moveTo(i))
			{
				if (tempInfo.isArrived())
				{
					cout << tempInfo.count;
					return 0;
				}
				moveQueue.push(tempInfo);
			}
		}
	}
	cout << -1;
}