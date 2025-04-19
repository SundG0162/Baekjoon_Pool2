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

struct node
{
	int from, to, weight;

	bool operator<(const node& node)
	{
		return weight < node.weight;
	}
	bool operator>(const node& node)
	{
		return weight > node.weight;
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

	int v, e;
	cin >> v >> e;

	vector<node> nodeVec(e + 1);

	for (int i = 0, a, b, c; i < e; i++)
	{
		cin >> a >> b >> c;
		node node{ a,b,c };
		nodeVec[i] = node;
	}

	sort(BEGIN_TO_END(nodeVec), less<>());

	vector<int> parent(v + 1);
	for (int i = 1; i <= v; i++)
	{
		parent[i] = i;
	}


	int sum = 0;
	int max = 0;
	for (auto& node : nodeVec)
	{
		int uParent = findParent(parent, node.from);
		int vParent = findParent(parent, node.to);
		if (uParent != vParent)
		{
			parent[uParent] = vParent;
			sum += node.weight;	
			max = std::max(node.weight, max);
		}
	}
	cout << sum - max;
}

