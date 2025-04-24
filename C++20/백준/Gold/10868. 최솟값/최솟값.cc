#include <bits/stdc++.h>
using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

int sequence[100001];
int min_segTree[400001];

int min_build(int node, int start, int end)
{
	if (start == end)
	{
		min_segTree[node] = sequence[start];
		return min_segTree[node];
	}

	int mid = (start + end) / 2;

	long long leftMin = min_build(node * 2, start, mid);
	long long rightMin = min_build(node * 2 + 1, mid + 1, end);

	return min_segTree[node] = min(leftMin, rightMin);
}

int min_query(int node, int start, int end, int qStart, int qEnd)
{
	if (end < qStart || start > qEnd)
		return 1000000001;
	if (start >= qStart && end <= qEnd)
		return min_segTree[node];

	int mid = (start + end) / 2;
	int leftChild = min_query(node * 2, start, mid, qStart, qEnd);
	int rightChild = min_query(node * 2 + 1, mid + 1, end, qStart, qEnd);
	return min(leftChild, rightChild);
}

int main()
{
	FAST_PRINT;

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> sequence[i];
	}

	min_build(1, 1, n);

	for (int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b;
		cout << min_query(1, 1, n, a, b) << '\n';
	}
}