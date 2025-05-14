#include<bits/stdc++.h>

using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))
#define INF 1e9

vector<int>adj[100001];
int parent[100001];
int level[100001];

int lca(int a, int b)
{
	if (level[a] < level[b])
		swap(a, b);

	while (level[a] != level[b])
	{
		a = parent[a];
	}

	while (a != b)
	{
		a = parent[a];
		b = parent[b];
	}

	return a;
}

void buildTree(int node, int pNode)
{
	parent[node] = pNode;
	level[node] = level[pNode] + 1;

	for (int i = 0; i < adj[node].size(); i++)
	{
		if (adj[node][i] == pNode)
			continue;
		buildTree(adj[node][i], node);
	}
}

int main()
{
	FAST_PRINT;

	int n;
	cin >> n;

	for (int i = 0, a, b; i < n - 1; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	level[1] = 1;
	buildTree(1, 1);

	int m;
	cin >> m;

	for (int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}
}