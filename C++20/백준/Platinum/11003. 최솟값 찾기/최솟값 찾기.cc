#include<bits/stdc++.h>

using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

int sequence[5000001];

int main()
{
	FAST_PRINT;

	int n, l;
	cin >> n >> l;

	deque<int> dq;
	for (int i = 1; i <= n; i++)
	{
		cin >> sequence[i];
		while (!dq.empty() && sequence[dq.back()] >= sequence[i]) // 현재 들어온 입력보다 큰 값은 제외.
			dq.pop_back();

		dq.push_back(i);
		if (dq.front() < i - l + 1) // 범위 벗어나도 제외
			dq.pop_front();

		cout << sequence[dq.front()] << ' ';
	}
}