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

int dist[801];
vector<pair<int, int>> adjVec[801];

void dijkstra(int n)
{
	std::fill(dist, dist + 801, INT32_MAX);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	dist[n] = 0;
	pq.emplace(0, n);
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (cost > dist[current])
			continue;

		for (int i = 0; i < adjVec[current].size(); i++)
		{
			auto p = adjVec[current][i];
			int newCost = p.second + cost;
			if (newCost < dist[p.first])
			{
				dist[p.first] = newCost;
				pq.emplace(newCost, p.first);
			}
		}
	}
}

int main()
{
	FAST_PRINT;

	int n, e;
	cin >> n >> e;

	for (int i = 0, a, b, c; i < e; i++)
	{
		cin >> a >> b >> c;
		adjVec[a].emplace_back(b, c);
		adjVec[b].emplace_back(a, c);
	}

	int v1, v2;
	cin >> v1 >> v2;

	dijkstra(1);
	int oneToV1 = dist[v1];
	int oneToV2 = dist[v2];

	dijkstra(v1);
	int v1ToV2 = dist[v2];
	int v1ToN = dist[n];

	dijkstra(v2);
	int v2ToV1 = dist[v1];
	int v2ToN = dist[n];

	int v1ToV2Sum = INT32_MAX;
	int v2ToV1Sum = INT32_MAX;
	if (oneToV1 != INT32_MAX && v1ToV2 != INT32_MAX && v2ToN != INT32_MAX)
		v1ToV2Sum = oneToV1 + v1ToV2 + v2ToN;
	if (oneToV2 != INT32_MAX && v2ToV1 != INT32_MAX && v1ToN != INT32_MAX)
		v2ToV1Sum = oneToV2 + v2ToV1 + v1ToN;
	if (v1ToV2Sum == v2ToV1Sum && v1ToV2Sum == INT32_MAX)
		cout << -1;
	else
		cout << std::min(v1ToV2Sum, v2ToV1Sum);
}