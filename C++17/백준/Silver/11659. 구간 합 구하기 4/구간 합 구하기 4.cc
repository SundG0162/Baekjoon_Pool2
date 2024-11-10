#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int dp[100001];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1, x; i <= n; i++)
	{
		cin >> x;
		if (i == 1)
		{
			dp[i] = x;
			continue;
		}
		dp[i] = dp[i - 1] + x;
	}
	for (int k = 0, i, j; k < m; k++)
	{
		cin >> i >> j;
		cout << dp[j] - dp[i - 1] << '\n';
	}
}