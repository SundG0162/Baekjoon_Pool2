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

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()

long long dp[101][10];

int main()
{
	FAST_PRINT;

	int n;
	cin >> n;

	for (int i = 1; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j + 1 <= 9)
				dp[i][j] += dp[i - 1][j + 1];
			if (j - 1 >= 0)
				dp[i][j] += dp[i - 1][j - 1];
			dp[i][j] %= 1000000000;
		}
	}
	
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += dp[n][i];
		sum %= 1000000000;
	}
	cout << sum;
}
