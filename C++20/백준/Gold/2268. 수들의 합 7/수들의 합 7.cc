#include <bits/stdc++.h>
using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

long long sequence[1000001];
long long segTree[4000001];

//현재 보고 있는 노드, 현재 노드가 담당 중인 구간, 합을 구하고자 하는 구간
long long query(int node, int start, int end, int qStart, int qEnd)
{
	if (end < qStart || start > qEnd)
		return 0;
	if (start >= qStart && end <= qEnd)
		return segTree[node];

	int mid = (start + end) / 2;
	long long leftChild = query(node * 2, start, mid, qStart, qEnd);
	long long rightChild = query(node * 2 + 1, mid + 1, end, qStart, qEnd);
	return leftChild + rightChild;
}

void update(int node, int start, int end, int target, long long value)
{
	if (target < start || target > end)
		return;
	if (start == end)
	{
		segTree[node] = value;
		return;
	}

	int mid = (start + end) / 2;

	update(node * 2, start, mid, target, value);
	update(node * 2 + 1, mid + 1, end, target, value);

	segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}


int main()
{
	FAST_PRINT;

	int n, m;
	cin >> n >> m;

	MEMSET(sequence, 0);
	MEMSET(segTree, 0);

	for (long long i = 0, a, b, c; i < m; i++)
	{
		cin >> a >> b >> c;

		if (a == 1)
		{
			update(1, 1, n, b, c);
		}
		else if (a == 0)
		{
			if (b > c) 
				swap(b, c);
			cout << query(1, 1, n, b, c) << '\n';
		}
	}
}