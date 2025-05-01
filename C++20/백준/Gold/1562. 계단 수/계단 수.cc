#include <bits/stdc++.h>
using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

int N;
long long dp[101][10][1 << 10];

long long findStairNum(int n, int curDigit, int visited)
{
	if (dp[n][curDigit][visited] != -1)
		return dp[n][curDigit][visited];
	if (n == N)
		return dp[n][curDigit][visited] = (visited == (1 << 10) - 1) ? 1 : 0;
	long long res = 0;
	if (curDigit > 0)
		res += findStairNum(n + 1, curDigit - 1, visited | (1 << (curDigit - 1))) % 1000000000;
	if (curDigit < 9)
		res += findStairNum(n + 1, curDigit + 1, visited | (1 << (curDigit + 1))) % 1000000000;
	return dp[n][curDigit][visited] = res;
}

int main()
{
	FAST_PRINT;

	MEMSET(dp, -1);

	cin >> N;

	long long res = 0;
	for (int i = 1; i < 10; i++)
	{
		res += findStairNum(1, i, 1 << i) % 1000000000;
	}
	cout << res % 1000000000;
	return 0;
}