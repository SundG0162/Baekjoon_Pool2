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

char map[51][51];

//visited[y][x][keyState]
//keyState : 열쇠는 먹기 안먹기 2개의 선택지가 있고 총 6개이니 2^6 = 64
bool visited[51][51][64];

struct coord
{
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
		return x < 0 || y < 0 || x >= m || y >= n;
	}
	char getChar()
	{
		return map[y][x];
	}
};

coord dir[4]{ {1,0},{0,1},{-1,0},{0,-1} };

struct moveInfo
{
	// 비트 마스킹을 이용한 키 상태 입력
	// keyState |= 1 << (먹은 키 문자 - 'a');
	// 해당 key가 있는지 알기 위해선?
	// 키는 사용하고 나면 없애야 하는가? X
	// (keyState & 1 << (열쇠로 열 문 - 'A')) != 0
	int keyState = 0;
	int count = 0;
	coord curPos;

	void setKey(char key)
	{
		keyState |= 1 << (key - 'a');
	}

	bool hasKey(char door)
	{
		return (keyState & 1 << (door - 'A')) != 0;
	}

	bool moveTo(coord toMove)
	{
		curPos += toMove;
		if (curPos.isOutOfRange())
			return false;
		if (visited[curPos.y][curPos.x][keyState])
			return false;
		char movedChar = curPos.getChar();
		if (movedChar == '#')
			return false;
		if (std::isalpha(movedChar))
		{
			if (std::islower(movedChar))
			{
				setKey(movedChar);
			}
			else
			{
				if (!hasKey(movedChar))
					return false;
			}
		}
		visited[curPos.y][curPos.x][keyState] = true;
		count++;
		return true;
	}
};

int main()
{
	MEMSET(visited, false);

	cin >> n >> m;

	coord startPos{};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '0')
				startPos = { j,i };
		}
	}

	queue<moveInfo> moveQueue;

	moveInfo first;
	first.curPos = startPos;
	moveQueue.push(first);

	while (!moveQueue.empty())
	{
		moveInfo info = moveQueue.front();
		moveQueue.pop();

		for (int i = 0; i < 4; i++)
		{
			moveInfo tempInfo = info;
			if (tempInfo.moveTo(dir[i]))
			{
				if (tempInfo.curPos.getChar() == '1')
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