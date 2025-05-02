#include <bits/stdc++.h>
using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

long long segTree[1000001 * 4];
long long sequence[1000001];
long long lazy[1000001 * 4];

void propagate(int node, int start, int end)
{
	if (lazy[node] != 0)
	{
		segTree[node] += (end - start + 1) * lazy[node]; // 구간합
		if (start != end)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
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

	segTree[node] = segTree[left] + segTree[right];
}

void update(int node, int start, int end, int uStart, int uEnd, long long  value)
{
	propagate(node, start, end);

	if (uStart > end || uEnd < start)
		return;

	if (uStart <= start && end <= uEnd)
	{
		lazy[node] += value;
		propagate(node, start, end);
		return;
	}

	int mid = (start + end) / 2;
	int left = node * 2;
	int right = left + 1;

	update(left, start, mid, uStart, uEnd, value);
	update(right, mid + 1, end, uStart, uEnd, value);

	segTree[node] = segTree[left] + segTree[right];
}

long long query(int node, int start, int end, int qStart, int qEnd)
{
	propagate(node, start, end);

	if (qStart > end || qEnd < start)
		return 0;
	if (start >= qStart && end <= qEnd)
		return segTree[node];

	int mid = (start + end) / 2;
	int left = node * 2;
	int right = left + 1;

	return query(left, start, mid, qStart, qEnd) + query(right, mid + 1, end, qStart, qEnd);
}


int main()
{
	FAST_PRINT;

	MEMSET(lazy, 0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> sequence[i];
	}

	build(1, 1, n);

	for (long long i = 0, a, b, c; i < m + k; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			long long d;
			cin >> d;
			update(1, 1, n, b, c, d);
		}
		else if (a == 2)
		{
			cout << query(1, 1, n, b, c) << '\n';
		}
	}
}

