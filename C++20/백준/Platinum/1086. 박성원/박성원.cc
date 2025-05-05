#include <bits/stdc++.h>
using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

int N, K;
long long dp[1 << 15][101];
int num_mods[16];
int ten_mods[51];
int lens[16];
string nums[16];

int getMod(string& str)
{
	int res = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		int digit = str[i] - '0';
		res = (res * 10 + digit) % K;
	}
	return res;
}

long long factorial(int x)
{
	long long res = 1;
	for (int i = 2; i <= x; i++)
		res *= i;
	return res;
}

long long gcd(long long x, long long y)
{
	if (y == 0)
		return x;
	return gcd(y, x % y);
}

int main()
{
	FAST_PRINT;
	MEMSET(dp, 0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
		lens[i] = nums[i].size();
	}
	cin >> K;
	for (int i = 0; i < N; i++)
		num_mods[i] = getMod(nums[i]);
	dp[0][0] = 1;

	ten_mods[0] = 1 % K;
	for (int i = 1; i <= 50; ++i) 
	{
		ten_mods[i] = (ten_mods[i - 1] * 10) % K;
	}


	for (int mask = 0; mask < (1 << N); mask++)
	{
		for (int mod = 0; mod < K; mod++)
		{
			if (dp[mask][mod] == 0)
				continue;

			for (int i = 0; i < N; i++)
			{
				if (!(mask & (1 << i)))
				{
					int new_mask = mask | (1 << i);
					int new_mod = (mod * ten_mods[lens[i]] % K + num_mods[i]) % K;

					dp[new_mask][new_mod] += dp[mask][mod];
				}
			}
		}
	}

	long long x = dp[(1 << N) - 1][0];
	long long y = factorial(N);

	if (x == 0) 
	{
		cout << "0/1";
		return 0;
	}

	long long g = gcd(x, y);

	cout << x / g << "/" << y / g;
}

