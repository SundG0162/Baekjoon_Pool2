#include<iostream>
#include<string>
#include<cstring>
#include<queue>
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
using std::stack;
using std::string;

vector<std::pair<int, int>> adjVec[20001];
int dist[20001];

int main()
{
	int V, E, K;
	cin >> V >> E >> K;

	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		adjVec[u].push_back({ v,w });
	}

	std::fill(dist, dist + 20001, 1e9);
	dist[K] = 0;

	std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, std::greater<>> pq;
	pq.push({ 0, K });
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (dist[current] < cost)
			continue;

		for (int i = 0; i < adjVec[current].size(); i++)
		{
			auto p = adjVec[current][i];
			int newCost = cost + p.second;
			if (newCost < dist[p.first])
			{
				dist[p.first] = newCost;
				pq.push({ newCost, p.first });
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == 1e9)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}
}