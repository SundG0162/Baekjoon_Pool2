#include<bits/stdc++.h>

using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))
#define INF 1e9


int main()
{
	FAST_PRINT;
	long long n, k;
	cin >> n >> k;

	// n : 3
	// k : 9
	// answer : 9

	// cnt = 0; 
	// cnt += min(mid / i, n);
	// 

	long long left = 1;
	long long right = n * n;

	long long cnt = 0;

	int ans = 0;

	while (right >= left)
	{
		long long mid = (right + left) / 2;
		cnt = 0;

		for (int i = 1; i <= n; i++)
			cnt += min(mid / i, n);

		if (cnt >= k)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}

	}

	cout << left;
}