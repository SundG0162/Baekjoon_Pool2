#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::stack;
using std::string;

int dp[1000001];

int main()
{
	int n;
	cin >> n;

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)
			dp[i] = std::min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0)
			dp[i] = std::min(dp[i], dp[i / 2] + 1);
	}

	cout << dp[n] << '\n';

	cout << n << " ";
	int process = n;
	for (int i = 0; i < dp[n]; i++)
	{
		int a = process-1;
		if (process % 3 == 0)
		{
			if (dp[a] > dp[process / 3])
				a = process / 3;
		}
		if (process % 2 == 0)
		{
			if (dp[a] > dp[process / 2])
				a = process / 2;
		}
		cout << a << " ";
		process = a;
	}
}