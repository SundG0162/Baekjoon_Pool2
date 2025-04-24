#include <bits/stdc++.h>
using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

long long sequence[100001];
long long segTree[400001];


// 초기값 설정
long long build(int node, int start, int end)
{
	if (start == end)
	{
		segTree[node] = sequence[start];
		return segTree[node];
	}

	int mid = (start + end) / 2;

	long long leftSum = build(node * 2, start, mid);
	long long rightSum = build(node * 2 + 1, mid + 1, end);

	segTree[node] = leftSum + rightSum;
	return segTree[node];
}

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

	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		cin >> sequence[i];
	}

	build(1, 1, n);

	for (long long i = 0, x, y, a, b; i < q; i++)
	{
		cin >> x >> y >> a >> b;
		if (x > y)
			swap(x, y);
		cout << query(1, 1, n, x, y) << '\n';
		update(1, 1, n, a, b);
	}
}