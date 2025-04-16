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

int visited[100001];
int count[100001];

int main()
{
	MEMSET(visited, -1);
	MEMSET(count, 0);

	int n, k;
	cin >> n >> k;

	queue<int> moveQueue;

	visited[n] = 0;
	count[n] = 1;

	int minCnt = INT32_MAX;
	int totalCnt = 0;
	moveQueue.push(n);
	while (!moveQueue.empty())
	{
		int curN = moveQueue.front();
		moveQueue.pop();

		int movements[3] = { curN + 1, curN - 1, curN * 2 };

		for (int i = 0; i < 3; i++)
		{
			int m = movements[i];
			if (m < 0 || m > 100000)
				continue;
			if (visited[m] == -1)
			{
				visited[m] = visited[curN] + 1;
				count[m] = count[curN];
				moveQueue.push(m);
			}
			else if (visited[m] == visited[curN] + 1) 
			{
				count[m] += count[curN];
			}
		}
	}

	cout << visited[k] << '\n' << count[k];
}