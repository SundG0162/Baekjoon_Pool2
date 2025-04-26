#include <bits/stdc++.h>
using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

int n;

int height[100001];
int min_segTree[400001];

void build(int node, int start, int end)
{
	if (start == end)
	{
		min_segTree[node] = start;
		return;
	}

	int mid = (start + end) / 2;

	int left = node * 2;
	int right = left + 1;

	build(left, start, mid);
	build(right, mid + 1, end);

	int leftHeight = height[min_segTree[left]];
	int rightHeight = height[min_segTree[right]];
	if (leftHeight < rightHeight)
		min_segTree[node] = min_segTree[left];
	else
		min_segTree[node] = min_segTree[right];
}

int query(int node, int start, int end, int qStart, int qEnd)
{
	if (qStart > end || qEnd < start || start > end)
		return -1;
	if (start >= qStart && end <= qEnd)
		return min_segTree[node];

	int mid = (start + end) / 2;

	int leftMinIdx = query(node * 2, start, mid, qStart, qEnd);
	int rightMinIdx = query(node * 2 + 1, mid + 1, end, qStart, qEnd);

	if (leftMinIdx == -1)
		return rightMinIdx;
	if (rightMinIdx == -1)
		return leftMinIdx;

	int leftHeight = height[leftMinIdx];
	int rightHeight = height[rightMinIdx];
	if (leftHeight < rightHeight)
		return leftMinIdx;
	return rightMinIdx;
}

long long getMaxArea(int start, int end)
{
	if (start > end)
		return 0;
	if (start == end)
		return height[start];

	int pivot = query(1, 1, n, start, end);

	long long curArea = (long long)height[pivot] * (end - start + 1);
	long long leftArea = getMaxArea(start, pivot - 1);
	long long rightArea = getMaxArea(pivot + 1, end);

	return max({ curArea, leftArea, rightArea });
}

bool solve()
{
	cin >> n;
	if (n == 0)
		return false;

	for (int i = 1; i <= n; i++)
	{
		cin >> height[i];
	}

	build(1, 1, n);

	cout << getMaxArea(1, n) << '\n';

	return true;
}

int main()
{
	FAST_PRINT;
	solve();
}