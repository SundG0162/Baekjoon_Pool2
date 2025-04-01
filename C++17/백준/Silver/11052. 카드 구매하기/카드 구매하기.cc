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


int card[1001];
int dp[1001];

int main()
{
	int n;
	cin >> n;

	memset(dp, 0, sizeof(dp));


	for (int i = 1; i <= n; i++)
	{
		cin >> card[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = std::max(dp[i], dp[i - j] + card[j]);
		}
	}

	cout << dp[n];
}
