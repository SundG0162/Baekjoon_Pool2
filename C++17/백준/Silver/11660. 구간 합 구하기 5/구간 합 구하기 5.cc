#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <set>

using namespace std;
int arr[1025][1025];
int dp[1025][1025];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}

	for (int i = 0, x1, y1, x2, y2; i < m; i++)
	{
		cin >> y1 >> x1 >> y2 >> x2;
		cout << dp[y2][x2] + dp[y1 - 1][x1 - 1] - dp[y1 - 1][x2] - dp[y2][x1 - 1] << '\n';
	}
}