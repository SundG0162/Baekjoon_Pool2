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

	for (int i = 0; i < m; i++)
	{
		int cmd, a, b;
		cin >> cmd >> a >> b;
		int aParent = findParent(parent, a);
		int bParent = findParent(parent, b);
		if (cmd == 0)
		{
			if (aParent != bParent)
				parent[aParent] = bParent;
		}
		else
		{
			cout << (aParent == bParent ? "YES\n" : "NO\n");
		}
	}
}