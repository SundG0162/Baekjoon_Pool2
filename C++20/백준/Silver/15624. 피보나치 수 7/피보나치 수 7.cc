#include<bits/stdc++.h>

using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

long long dp[1000001];

int main()
{
	FAST_PRINT;

	int n;
	cin >> n;

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
	}

	cout << dp[n];
}