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

struct node
{
	vector<int> connected;
};

node nodes[100001];
int sizeDP[100001];

int setSize(int parentIdx, int nodeIdx)
{
	if (sizeDP[nodeIdx] >= 1)
		return sizeDP[nodeIdx];
	int sum = 1;
	for (int connect : nodes[nodeIdx].connected)
	{
		if (connect == parentIdx)
			continue;
		sum += setSize(nodeIdx, connect);
	}
	sizeDP[nodeIdx] = sum;
	return sum;
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//O(N + Q) <<최선아님?
	//O(100000 + 100000) 
	memset(sizeDP, 0, sizeof(sizeDP));

	int n, r, q;
	cin >> n >> r >> q;

	for (int i = 0, u, v; i < n - 1; i++)
	{
		cin >> u >> v;
		nodes[u].connected.push_back(v);
		nodes[v].connected.push_back(u);
	}

	setSize(0, r);

	for (int i = 0, u; i < q; i++)
	{
		cin >> u;
		cout << sizeDP[u] << '\n';
	}
}