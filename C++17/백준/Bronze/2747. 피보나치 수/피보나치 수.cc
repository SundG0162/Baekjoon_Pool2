#include <iostream>
#include <algorithm>
using namespace std;

int dp[46];

int main()
{
	int n;
	cin >> n;

	dp[1] = dp[2] = 1;
	dp[3] = 2;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];
}