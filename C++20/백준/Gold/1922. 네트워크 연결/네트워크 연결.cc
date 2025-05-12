#include<bits/stdc++.h>

using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))
#define INF 1e9

struct node
{
	int from, to, weight;

	bool operator<(const node& node)
	{
		return weight < node.weight;
	}
	bool operator>(const node& node)
	{
		return weight < node.weight;
	}
};

int findParent(vector<int>& parent, int nodeIdx)
{
	if (parent[nodeIdx] != nodeIdx)
		parent[nodeIdx] = findParent(parent, parent[nodeIdx]);
	return parent[nodeIdx];
}

int main()
{
	FAST_PRINT;

	int n, m;
	cin >> n >> m;

	vector<node> nodeVec(m + 1);
	vector<int> parent(n + 1);

	for (int i = 1, a, b, c; i <= m; i++)
	{
		cin >> a >> b >> c;
		nodeVec[i] = { a, b, c };
	}

	sort(BEGIN_TO_END(nodeVec), greater<>());

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	int sum = 0;
	for (auto& node : nodeVec)
	{
		int uParent = findParent(parent, node.from);
		int vParent = findParent(parent, node.to);
		if (uParent != vParent)
		{
			parent[uParent] = vParent;
			sum += node.weight;
		}
	}
	cout << sum;
}