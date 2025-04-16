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
#define RBEGIN_TO_REND(vec) vec.rbegin(), vec.rend()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))
#define MEMCPY(to, arr) memcpy(to, arr, sizeof(arr))

int findParent(vector<int>& parent, int node)
{
	if (parent[node] != node)
		parent[node] = findParent(parent, parent[node]);
	return parent[node];
}

int main()
{
	FAST_PRINT;

	int n, m;
	cin >> n >> m;

	vector<int> parent(n + 1);
	for (int i = 0; i <= n; i++)
		parent[i] = i;

	for (int i = 1, connected; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> connected;
			if (connected)
			{
				int iParent = findParent(parent, i);
				int jParent = findParent(parent, j);
				if (iParent != jParent)
					parent[iParent] = jParent;
			}
		}
	}

	int prev = -1;
	for (int i = 0, city; i < m; i++)
	{
		cin >> city;
		if (prev == -1)
			prev = findParent(parent, city);
		else
		{
			int cur = findParent(parent, city);
			if (cur == prev)
				prev = cur;
			else
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
}