#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

unsigned long long dp[117];
int main()
{
    int n;
    cin >> n;
    dp[1] = dp[2] = dp[3] = 1;

    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 3];
    }
    cout << dp[n];
}