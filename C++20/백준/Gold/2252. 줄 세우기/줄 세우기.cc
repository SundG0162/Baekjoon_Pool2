#include<bits/stdc++.h>

using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))
#define INF 1e9


int main()
{
	FAST_PRINT;

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adjList(n + 1);
	vector<int> adjDeg(n + 1, 0);

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		adjList[a].push_back(b);
		adjDeg[b]++;
	}

	queue<int> nodeQueue;
	for (int i = 1; i <= n; i++)
	{
		if (adjDeg[i] == 0)
		{
			nodeQueue.push(i);
		}
	}

	vector<int> res;
	while (!nodeQueue.empty())
	{
		int node = nodeQueue.front();
		nodeQueue.pop();

		for (int e : adjList[node])
		{
			adjDeg[e]--;
			if (adjDeg[e] == 0)
				nodeQueue.push(e);
		}

		res.push_back(node);
	}

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}

}