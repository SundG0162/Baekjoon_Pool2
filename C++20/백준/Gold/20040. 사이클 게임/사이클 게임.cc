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

	vector<int> parent(n + 1);
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	int turn = 0;

	for (int i = 0, u, v; i < m; i++)
	{
		cin >> u >> v;
		if (turn != 0)
			continue;

		int uParent = findParent(parent, u);
		int vParent = findParent(parent, v);
		if (uParent == vParent)
		{
			turn = i + 1;
		}
		else
		{
			parent[uParent] = vParent;
		}
	}

	cout << turn;
}

