#include <bits/stdc++.h>
using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

int main()
{
	FAST_PRINT;

	long long min, max;
	cin >> min >> max;

	long long n = max - min + 1;

	vector<bool> square_free(n, false);
	long long  answer = n;
	for (long long i = 2; i * i <= max; i++)
	{
		long long square = i * i;
		long long start = (min + square - 1) / square * square;
		for (long long j = start; j <= max; j += square)
		{
			if (!square_free[j - min])
			{
				square_free[j - min] = true;
				answer--;
			}
		}
	}

	cout << answer;
}