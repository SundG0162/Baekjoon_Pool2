#include<bits/stdc++.h>

using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

int sequence[500001];
int segTree[2000001];
int lazy[2000001];

void propagate(int node, int start, int end)
{
	if (lazy[node] != 0)
	{
		if ((end - start + 1) % 2 != 0)
			segTree[node] ^= lazy[node];
		if (start != end)
		{
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void build(int node, int start, int end)
{
	if (start == end)
	{
		segTree[node] = sequence[start];
		return;
	}

	int mid = (start + end) / 2;
	int left = node * 2;
	int right = left + 1;
	build(left, start, mid);
	build(right, mid + 1, end);
	segTree[node] = segTree[left] ^ segTree[right];
}

void update(int node, int start, int end, int uStart, int uEnd, int value)
{
	propagate(node, start, end);

	if (uStart > end || uEnd < start)
		return;

	if (uStart <= start && end <= uEnd)
	{
		lazy[node] = value;
		propagate(node, start, end);
		return;
	}

	int mid = (start + end) / 2;
	int left = node * 2;
	int right = left + 1;

	update(left, start, mid, uStart, uEnd, value);
	update(right, mid + 1, end, uStart, uEnd, value);

	segTree[node] = segTree[left] ^ segTree[right];
}

int query(int node, int start, int end, int qStart, int qEnd)
{
	propagate(node, start, end);
	if (start > qEnd || end < qStart)
		return 0;
	if (start >= qStart && end <= qEnd)
		return segTree[node];

	int mid = (start + end) / 2;
	return query(node * 2, start, mid, qStart, qEnd) ^ query(node * 2 + 1, mid + 1, end, qStart, qEnd);
}

int main()
{
	MEMSET(lazy, 0);
	FAST_PRINT;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> sequence[i];

	build(1,0,n-1);

	int m;
	cin >> m;

	for (int i = 0, a, b, c; i < m; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			int k;
			cin >> k;
			update(1, 0, n - 1, b, c, k);
		}
		else if (a == 2)
		{
			cout << query(1, 0, n-1, b, c) << '\n';
		}
	}
}