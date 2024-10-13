#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int dp[11];

int main()
{
	int t;
	cin >> t;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		for (int j = 4; j <= n; j++)
		{
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		}
		cout << dp[n] << '\n';
	}
	return 0;
}