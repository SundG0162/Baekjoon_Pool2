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
using std::priority_queue;
using std::queue;
using std::deque;
using std::stack;
using std::string;
using std::pair;
using std::unordered_map;
using std::greater;
using std::less;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

int checkPelindrome(vector<int>& seq, vector<vector<int>>& dp, int s, int e)
{
	if (dp[s][e] != -1)
		return dp[s][e];
	if (s == e)
		return dp[s][e] = 1;
	if (s == e - 1)
		return dp[s][e] = seq[s] == seq[e];

	return 	dp[s][e] = checkPelindrome(seq, dp, s + 1, e - 1) && (seq[s] == seq[e]);
}

int main()
{
	FAST_PRINT;

	//dp[i][j] = 수열의 i번째 수 부터 j번째 수가 펠린드롬 수면 1 아니면 0
	//dp[i][j] = dp[i+1][j-1] && seq[i] == seq[j];

	int n;
	cin >> n;

	vector<int> seqVec(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
	for (int i = 1; i <= n; i++)
	{
		cin >> seqVec[i];
	}

	int m;
	cin >> m;
	for (int i = 0, s, e; i < m; i++)
	{
		cin >> s >> e;

		int checkRes = checkPelindrome(seqVec, dp, s, e);
		cout << checkRes << '\n';
	}
}

