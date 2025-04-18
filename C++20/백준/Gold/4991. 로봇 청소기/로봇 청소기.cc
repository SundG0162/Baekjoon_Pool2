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
#define COORD(p) p.second][p.first

#define VERY_BIG_NUMBER 1e9

int w, h;
int dustCount;
bool visited[21][21];
int dist[11][1 << 11];

struct distInfo
{
	int count;
	pair<int, int> curPos;

	bool moveTo(vector<vector<char>>& map, pair<int, int> dir)
	{
		curPos.first += dir.first;
		curPos.second += dir.second;
		if (isOutOfRange())
			return false;
		if (visited[COORD(curPos)])
			return false;
		if (map[COORD(curPos)] == 'x')
			return false;
		count++;
		return true;
	}

	bool isOutOfRange()
	{
		return curPos.first < 0 || curPos.second < 0 || curPos.first >= w || curPos.second >= h;
	}
};

int tsp(vector<vector<int>>& adj, int current, int visit)
{
	int maxBit = (1 << dustCount) - 1; // 모든 먼지를 치운다면 비트가 딱 이모냥이 됨.
	int leftDust = ~visit & maxBit; // 남은 먼지의 Index를 1로, 치운 먼지의 Index를 0으로 바꿈
	if ((leftDust & (leftDust - 1)) == 0) // leftDust가 2의 거듭 제곱(하나의 비트만 1)인지 확인. 2의 거듭 제곱이면 값은 무조건 0
	{
		int idx = std::log2(leftDust);
		if (adj[current][idx] == VERY_BIG_NUMBER)
			return VERY_BIG_NUMBER;
		return adj[current][idx];
	}
	if (dist[current][visit] != -1)
		return dist[current][visit];

	int minCost = VERY_BIG_NUMBER;
	for(int i = 0; i < dustCount; i++)
	{
		if ((visit & (1 << i)) == 0 && adj[current][i] != VERY_BIG_NUMBER)
		{
			int toVisit = visit | (1 << i);
			int tempCost = adj[current][i] + tsp(adj, i, toVisit);
			minCost = std::min(tempCost, minCost);
		}
	}
	return dist[current][visit] = minCost;

}

void bfs(vector<vector<char>>& map, vector<vector<int>>& adj, int x, int y, int node)
{
	MEMSET(visited, false);

	int dirX[4]{ 1,-1,0,0 };
	int dirY[4]{ 0,0,1,-1 };

	queue<distInfo> distQueue;
	distInfo first;
	first.count = 0;
	first.curPos = { x,y };
	visited[COORD(first.curPos)] = true;		
	distQueue.push(first);

	while (!distQueue.empty())
	{
		distInfo info = distQueue.front();
		distQueue.pop();

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> dir = { dirX[i], dirY[i] };
			distInfo tempInfo = info;
			if (tempInfo.moveTo(map, dir))
			{
				visited[COORD(tempInfo.curPos)] = true;
				char c = map[COORD(tempInfo.curPos)];
				if (std::isdigit(c))
				{
					adj[node][c - '0'] = tempInfo.count;
				}
				distQueue.push(tempInfo);
			}
		}
	}
}

bool solve()
{
	cin >> w >> h;
	if (w == 0 || h == 0)
		return false;

	vector<vector<char>> map(h + 1, vector<char>(w + 1));

	dustCount = 1;
	pair<int, int> nodes[11];

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '*')
			{
				map[i][j] = dustCount + '0';
				nodes[dustCount++] = { j,i };
			}
			else if (map[i][j] == 'o')
			{
				map[i][j] = '0';
				nodes[0] = { j,i };
			}
		}
	}
	vector<vector<int>> adj(dustCount + 1, vector<int>(dustCount + 1, VERY_BIG_NUMBER));

	for (int i = 0; i <= dustCount; i++)
	{
		bfs(map, adj, nodes[i].first, nodes[i].second, i);
	}

	MEMSET(dist, -1);
	adj;
	int cleanDist = tsp(adj, 0, 1);
	if (cleanDist == VERY_BIG_NUMBER)
		cout << -1 << '\n';
	else
		cout << cleanDist << '\n';
	return true;
}

int main()
{
	FAST_PRINT;
	while (solve());
}

