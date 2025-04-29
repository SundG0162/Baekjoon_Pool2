#include <bits/stdc++.h>
using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

#define ll long long

ll n, p, q;
unordered_map<ll, ll> dp;

ll findSeq(ll i)
{
	if (i == 0)
		return 1;
	if (dp.find(i) != dp.end())
	{
		return dp[i];
	}
	return dp[i] = findSeq(i / p) + findSeq(i / q);
}

int main()
{
	FAST_PRINT;

	cin >> n >> p >> q;

	cout << findSeq(n);
}