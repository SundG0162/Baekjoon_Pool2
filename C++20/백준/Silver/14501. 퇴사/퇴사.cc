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

	// pair.first : 걸리는 시간, pair.second : 얻는 돈
	vector<std::pair<int, int>> consult(n + 1);
	for (int i = 1, t, p; i <= n; i++)
	{
		cin >> t >> p;
		consult[i] = { t,p };
	}

	// dp[i] = i일에 벌 수 있는 최대의 돈
	vector<int> dp(n + 2);

	for (int i = n; i >= 1; i--)
	{
		int endDay = i + consult[i].first;
		if (endDay <= n + 1)
		{
			dp[i] = std::max(dp[i + 1], consult[i].second + dp[endDay]);
		}
		else
		{
			dp[i] = dp[i + 1];
		}
	}
	cout << dp[1];
}