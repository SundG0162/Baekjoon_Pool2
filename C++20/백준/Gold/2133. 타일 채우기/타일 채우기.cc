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

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))


int main()
{
	int n;
	cin >> n;

	int dp[31];
	MEMSET(dp, 0);
	dp[0] = 1;
	dp[2] = 3;
	dp[4] = 11;

	for (int i = 6; i <= n; i += 2)
	{
		dp[i] = dp[i - 2] * 4 - dp[i - 4];
	}
	cout << dp[n];
}