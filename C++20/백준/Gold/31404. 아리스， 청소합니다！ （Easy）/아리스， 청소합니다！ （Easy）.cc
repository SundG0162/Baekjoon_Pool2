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

enum RULE_TYPE
{
	A = 0,
	B = 1
};

int h, w;
int dirX[4]{ 0,1,0,-1 };
int dirY[4]{ -1,0,1,0 };
bool visited[64][64][4][64 * 64]; // Y좌표, X좌표, 바라보는 방향, 먼지 최대 갯수
bool dust[64][64];

struct coord
{
	int x, y;
	void operator+=(const coord& other)
	{
		x += other.x;
		y += other.y;
	}
};

struct MoveInfo
{
	coord cur;
	RULE_TYPE rule;
	int dir;
	int count = 0;
	int remain = w * h - 1;
	int temp = 0;
	bool moveTo()
	{
		cur += {dirX[dir], dirY[dir]};
		if (isOutOfRange())
		{
			count -= temp;
			return false;
		}
		if (dust[cur.y][cur.x])
		{
			dust[cur.y][cur.x] = false;
			rule = A;
			temp = 0;
			remain--;
			if (remain == 0)
			{
				count++;
				return false;
			}
		}
		else
		{
			if (visited[cur.y][cur.x][dir][remain])
			{
				count -= temp;
				return false;
			}
			temp++;
			visited[cur.y][cur.x][dir][remain] = true;
			rule = B;
		}
		count++;
		return true;
	}

	bool isOutOfRange()
	{
		return cur.x < 0 || cur.y < 0 || cur.x >= w || cur.y >= h;
	}

	void rotate(int amount)
	{
		dir = (dir + amount) % 4;
	}
};



int main()
{
	MEMSET(visited, false);
	MEMSET(dust, true);
	cin >> h >> w;
	int r, c, d;
	cin >> r >> c >> d;
	vector<vector<int>> ruleA(h, vector<int>(w));
	vector<vector<int>> ruleB(h, vector<int>(w));
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			char c;
			cin >> c;
			ruleA[i][j] = c - '0';
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			char c;
			cin >> c;
			ruleB[i][j] = c - '0';
		}
	}

	MoveInfo move;
	move.dir = d;
	move.rule = A;
	move.cur = { c,r };
	dust[move.cur.y][move.cur.x] = false;
	move.rule = A;
	while (true)
	{
		if (move.rule == A)
			move.rotate(ruleA[move.cur.y][move.cur.x]);
		else
			move.rotate(ruleB[move.cur.y][move.cur.x]);

		if (!move.moveTo())
			break;
	}

	cout << move.count + 1;
}