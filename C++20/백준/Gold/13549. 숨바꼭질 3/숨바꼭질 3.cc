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


int main()
{
	FAST_PRINT;

	int n, k;
	cin >> n >> k;

	deque<int> moveQueue;
	vector<int> minTime(100001, -1);
	moveQueue.push_back(n);
	minTime[n] = 0;

	while (!moveQueue.empty())
	{
		int curPos = moveQueue.front();
		moveQueue.pop_front();

		int frontMove = curPos + 1;
		int backMove = curPos - 1;
		int teleport = curPos * 2;

		if (teleport <= 100000 && minTime[teleport] == -1)
		{
			minTime[teleport] = minTime[curPos];
			moveQueue.push_front(teleport);
		}
		if (backMove >= 0 && minTime[backMove] == -1)
		{
			minTime[backMove] = minTime[curPos] + 1;
			moveQueue.push_back(backMove);
		}
		if (frontMove <= 100000 && minTime[frontMove] == -1)
		{
			minTime[frontMove] = minTime[curPos] + 1;
			moveQueue.push_back(frontMove);
		}
	}

	cout << minTime[k];
}