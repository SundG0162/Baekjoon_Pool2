#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<deque>
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
using std::deque;
using std::stack;
using std::string;
using std::pair;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define RBEGIN_TO_REND(vec) vec.rbegin(), vec.rend()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))
#define MEMCPY(to, arr) memcpy(to, arr, sizeof(arr))

int main()
{
	FAST_PRINT;

	int n;
	cin >> n;

	vector<int> dp(n + 1, INT32_MAX);

	dp[0] = 0;
	dp[2] = 1;
	dp[4] = 2;
	dp[5] = 1;

	for (int i = 6; i <= n; i++)
	{
		if (dp[i - 2] == INT32_MAX && dp[i - 5] == INT32_MAX)
			dp[i] = INT32_MAX;
		else 
			dp[i] = std::min(dp[i - 2], dp[i - 5]) + 1;
	}

	if (dp[n] == INT32_MAX)
		cout << -1;
	else
		cout << dp[n];
}