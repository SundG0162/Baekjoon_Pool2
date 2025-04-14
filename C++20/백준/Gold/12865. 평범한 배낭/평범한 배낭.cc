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
using std::priority_queue;
using std::deque;
using std::stack;
using std::string;

#define ll long long

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

int main()
{
	FAST_PRINT;

	int n, k;
	cin >> n >> k;

	//pair.first : 무게, pair.second : 가치
	vector<std::pair<int, int>> stuffVec(n + 1);

	for (int i = 1; i <= n; i++)
	{
		int w, v;
		cin >> w >> v;
		stuffVec[i] = { w,v };
	}

	//dp[i][j] = 담을 수 있는 최대 무게가 j일때 i번째 물건까지 고려한 최대 가치.
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

	int max = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			int weight = stuffVec[i].first;
			int value = stuffVec[i].second;
			if (j - weight >= 0)
				dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight] + value);
			else
				dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
			max = std::max(dp[i][j], max);
		}
	}

	cout << max;
}
