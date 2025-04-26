#include <bits/stdc++.h>
using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

int n;

int sequence[500000];
int sortedSeq[500000];
long long cnt = 0;

void mergeSort(int start, int end)
{
	if (start >= end)
		return;

	int mid = (start + end) / 2;
	mergeSort(start, mid);
	mergeSort(mid + 1, end);
	int left = start, right = mid + 1, idx = start;

	while (left <= mid && right <= end)
	{
		if (sequence[left] <= sequence[right])
			sortedSeq[idx++] = sequence[left++];
		else
		{
			cnt += (mid - left + 1);
			sortedSeq[idx++] = sequence[right++];
		}
	}

	while (left <= mid)
		sortedSeq[idx++] = sequence[left++];
	while (right <= end)
		sortedSeq[idx++] = sequence[right++];

	for (int i = start; i <= end; i++)
		sequence[i] = sortedSeq[i];
}

int main()
{
	FAST_PRINT;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}

	mergeSort(0, n - 1);
	cout << cnt;
}