#include<bits/stdc++.h>

using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

bool switches[100001];
int segTree[400001];
bool lazy[400001];

void propagate(int node, int start, int end)
{
	if (lazy[node])
	{
        // 전체 개수 - 현재 켜진 개수 = 앞으로 켜질 개수
		segTree[node] = (end - start + 1) - segTree[node];
		if (start != end)
		{
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = false;
	}
}

void update(int node, int start, int end, int uStart, int uEnd)
{
	propagate(node, start, end);

	if (uStart > end || uEnd < start)
		return;

	if (uStart <= start && end <= uEnd)
	{
		lazy[node] = true;
		propagate(node, start, end);
		return;
	}

	int mid = (start + end) / 2;
	int left = node * 2;
	int right = left + 1;

	update(left, start, mid, uStart, uEnd);
	update(right, mid + 1, end, uStart, uEnd);

	segTree[node] = segTree[left] + segTree[right];
}

int query(int node, int start, int end, int qStart, int qEnd)
{
	propagate(node, start, end);
	if (start > qEnd || end < qStart)
		return 0;
	if (start >= qStart && end <= qEnd)
		return segTree[node];

	int mid = (start + end) / 2;
	return query(node * 2, start, mid, qStart, qEnd) + query(node * 2 + 1, mid + 1, end, qStart, qEnd);
}

int main()
{
	MEMSET(switches, false);
	MEMSET(segTree, 0);
	MEMSET(lazy, 0);
	FAST_PRINT;

	int n, m;
	cin >> n >> m;

	for (int i = 0, o, s, t; i < m; i++)
	{
		cin >> o >> s >> t;
		if (o == 0)
		{
			update(1, 1, n, s, t);
		}
		else if (o == 1)
		{
			cout << query(1, 1, n, s, t) << '\n';
		}
	}
}