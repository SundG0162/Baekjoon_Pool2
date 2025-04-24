#include <bits/stdc++.h>
using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

int sequence[100001];
int segTree[400001];

int build(int node, int start, int end)
{
	if (start == end)
	{
		return segTree[node] = start;
	}

	int mid = (start + end) / 2;

	int leftMin = build(node * 2, start, mid);
	int rightMin = build(node * 2 + 1, mid + 1, end);

	if (sequence[leftMin] < sequence[rightMin])
		segTree[node] = leftMin;
	else if (sequence[leftMin] > sequence[rightMin])
		segTree[node] = rightMin;
	else
		segTree[node] = min(leftMin, rightMin);
	return segTree[node];
}

int query(int node, int start, int end, int qStart, int qEnd)
{
	if (end < qStart || start > qEnd)
		return -1;
	if (start >= qStart && end <= qEnd)
		return segTree[node];

	int mid = (start + end) / 2;
	int leftChild = query(node * 2, start, mid, qStart, qEnd);
	int rightChild = query(node * 2 + 1, mid + 1, end, qStart, qEnd);
	if (leftChild == -1)
		return rightChild;
	if (rightChild == -1)
		return leftChild;
	if (sequence[leftChild] < sequence[rightChild])
		return leftChild;
	if (sequence[leftChild] > sequence[rightChild])
		return rightChild;
	return min(leftChild, rightChild);
}

void update(int node, int start, int end, int target, int value)
{
	if (target < start || target > end)
		return;
	if (start == end)
	{
		sequence[target] = value;
		return;
	}

	int mid = (start + end) / 2;

	int left = node * 2;
	int right = node * 2 + 1;
	update(left, start, mid, target, value);
	update(right, mid + 1, end, target, value);

	if (sequence[segTree[left]] < sequence[segTree[right]])
		segTree[node] = segTree[left];
	else if (sequence[segTree[left]] > sequence[segTree[right]])
		segTree[node] = segTree[right];
	else
		segTree[node] = min(segTree[left], segTree[right]);
}


int main()
{
	FAST_PRINT;
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> sequence[i];
	}

	build(1, 1, n);

	int m;
	cin >> m;
	for (int i = 0, a, b, c; i < m; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(1, 1, n, b, c);
		}
		else if (a == 2)
		{
			cout << query(1, 1, n, b, c) << '\n';
		}
	}
}