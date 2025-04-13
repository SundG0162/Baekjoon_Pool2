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

bool visited[101];

int main()
{
	FAST_PRINT;

	MEMSET(visited, false);

	int n, m;
	cin >> n >> m;
	std::unordered_map<int, int> snakeAndLadderMap;

	for (int i = 0; i < n + m; i++)
	{
		int from, to;
		cin >> from >> to;
		snakeAndLadderMap[from] = to;
	}

	// 순차적으로 현재 위치와 주사위 굴린 횟수.
	queue<std::pair<int, int>> moveQueue;
	moveQueue.push({ 1, 0 });

	while (!moveQueue.empty())
	{
		int curPos = moveQueue.front().first;
		int cnt = moveQueue.front().second;
		moveQueue.pop();

		for (int i = 1; i <= 6; i++)
		{
			int rolledPos = curPos + i;
			if (rolledPos > 100) 
				continue;

			if (rolledPos == 100)
			{
				cout << cnt + 1;
				return 0;
			}

			int nextPos = rolledPos;
			auto iter = snakeAndLadderMap.find(rolledPos);
			if (iter != snakeAndLadderMap.end())
				nextPos = iter->second;

			if (nextPos == 100)
			{
				cout << cnt + 1;
				return 0;
			}

			if (!visited[nextPos])
			{
				visited[nextPos] = true;
				moveQueue.push({ nextPos , cnt + 1 });
			}
		}
	}
}
