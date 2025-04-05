#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<map>
#include<unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::stack;
using std::string;

#define UP 0
#define DOWN 1
#define NONE 2

void solve()
{
	int n;
	cin >> n;

	vector<vector<int>> sticker(n + 1, vector<int>(2));
	vector<vector<int>> dp(n + 1, vector<int>(NONE + 1));

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> sticker[j][i];
		}
	}

	dp[0][UP] = sticker[0][UP];
	dp[0][DOWN] = sticker[0][DOWN];
	dp[0][NONE] = 0;

	for (int j = 1; j < n; j++)
	{
		dp[j][UP] = std::max(dp[j - 1][DOWN], dp[j - 1][NONE]) + sticker[j][UP];
		dp[j][DOWN] = std::max(dp[j - 1][UP], dp[j - 1][NONE]) + sticker[j][DOWN];
		dp[j][NONE] = *std::max_element(&dp[j-1][0], &dp[j-1][NONE] + 1);
	}

	cout << *std::max_element(&dp[n-1][0], &dp[n-1][NONE] + 1) << '\n';
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}