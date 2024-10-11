#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int dp[5001];

int main()
{
	int n;
	cin >> n;
	dp[1] = dp[2] = dp[4] = -1;
	dp[3] = dp[5] = 1;
	for (int i = 6; i <= n; i++)
	{
		int m = -1;
		if (dp[i - 3] > 0)
		{
			m = dp[i - 3] + 1;
		}
		if (dp[i - 5] > 0)
		{
			if (dp[i - 3] > 0)
			{
				m = min(dp[i - 3], dp[i - 5]) + 1;
			}
			else
			{
				m = dp[i - 5] + 1;
			}
		}
		dp[i] = m;
	}
	cout << dp[n];
	return 0;
}