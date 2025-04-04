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

vector<vector<std::pair<int, int>>> adj(10001);
int root = 1;

int maxDist = 0;

void dfs(int prev, int current, int weight)
{
	if (weight > maxDist)
	{
		maxDist = weight;
		root = current;
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
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}

	for (int i = 0; i < 2; i++)
	{
		dfs(root, root, 0);
	}

	cout << maxDist;
}