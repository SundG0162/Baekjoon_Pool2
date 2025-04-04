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

vector<vector<std::pair<int, int>>> adj(100001);
int fathestNode = 1;
int maxDist = 0;

void dfs(int prev, int current, int weight)
{
	if (weight > maxDist)
	{
		maxDist = weight;
		fathestNode = current;
	}
	for (auto& pair : adj[current])
	{
		if (pair.first == prev)
			continue;
		dfs(current, pair.first, pair.second + weight);
	}
}


int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int u;
		cin >> u;
		int v, w;
		while (true)
		{
			cin >> v;
			if (v == -1)
				break;
			cin >> w;
			adj[u].push_back({ v,w });
		}
	}

	dfs(0, 1, 0);
	maxDist = 0;
	dfs(0, fathestNode, 0);


	cout << maxDist;
}