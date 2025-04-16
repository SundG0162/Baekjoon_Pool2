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

	int V, E, K;
	cin >> V >> E >> K;
	vector<vector<pair<int, int>>> adjVec(V + 1);

	for (int i = 0, u, v, w; i < E; i++)
	{
		cin >> u >> v >> w;
		adjVec[u].emplace_back(v, w);
	}


	priority_queue<pair<int, int>, vector<std::pair<int, int>>, std::greater<>> pq;
	vector<int> distVec(V + 1, INT32_MAX);
	distVec[K] = 0;
	pq.push({ 0,K });

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (cost > distVec[current])
			continue;

		for (int i = 0; i < adjVec[current].size(); i++)
		{
			auto p = adjVec[current][i];
			int newCost = p.second + cost;
			if (newCost < distVec[p.first])
			{
				distVec[p.first] = newCost;
				pq.push({ newCost, p.first });
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		distVec[i] == INT32_MAX ? cout << "INF\n" : cout << distVec[i] << '\n';
	}
}