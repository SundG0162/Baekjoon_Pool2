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


int dp[50001];

int main()
{
	int n;
	cin >> n;
	dp[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		dp[i] = 50000;
		for (int j = 1; j * j <= i; j++)
		{
			dp[i] = std::min(dp[i - j * j] + 1, dp[i]);
		}
	}

	cout << dp[n];
}