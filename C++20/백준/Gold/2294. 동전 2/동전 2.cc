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
	int n, k;
	cin >> n >> k;
	vector<int> coinVec(n + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> coinVec[i];
	}

	vector<int> dp(k + 1, 100001);
	dp[0] = 0;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int idx = i - coinVec[j];
			if (idx >= 0)
			{
				dp[i] = std::min(dp[i], dp[idx] + 1);
			}
		}
	}

	if (dp[k] == 100001)
		cout << -1;
	else
		cout << dp[k];
}