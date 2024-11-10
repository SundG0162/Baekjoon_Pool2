#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int stairs[301];
int dp[301];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> stairs[i];
	}
	dp[0] = stairs[0];
	dp[1] = stairs[0] + stairs[1];
	dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);
	for (int i = 3; i < n; i++)
	{
		dp[i] = max(dp[i - 2] + stairs[i], stairs[i] + stairs[i - 1] + dp[i - 3]);
	}
	cout << dp[n - 1];
}