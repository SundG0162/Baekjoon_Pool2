#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
pair<int, int> dp[41];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	dp[0] = { 1,0 };
	dp[1] = { 0,1 };
	for (int i = 0, n; i < t; i++)
	{
		cin >> n;
		for (int i = 2; i <= n; i++)
		{
			dp[i] = { dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second };
		}
		cout << dp[n].first << ' ' << dp[n].second << '\n';
	}
}