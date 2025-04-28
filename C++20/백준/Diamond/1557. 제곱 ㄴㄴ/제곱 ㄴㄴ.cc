#include <bits/stdc++.h>
using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

long long getSquareFreeCount(vector<int>& mobius, long long x)
{
	long long res = 0;
	for (long long i = 1; i * i <= x; i++)
	{
		if (mobius[i] == 0)
			continue;
		// mobius가 0일땐 무승수가 아니니 더할 필요가 없음.
		// -1일땐 소인수의 개수가 홀수. 즉 배제해야 하니 이제 뺄셈
		// 1일땐 소인수의 개수가 짝수, 즉 포함해야 하니 이제 덧셈 ㅇㅇㅇㅇㅇㅇ 오케이 
		res += mobius[i] * (x / (i * i));
	}
	return res;
}

int main()
{
	FAST_PRINT;

	long long k;
	cin >> k;

	int limit = sqrt(2 * k) + 1;
	vector<bool> isPrime(limit, true); // 소수판단
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i * i < limit; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j < limit; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	vector<int> mobius(limit + 1, 1); // 뫼비우스 함수의 반환값 저장

	for (int i = 2; i < limit; i++) // 일단 k*2까지 증가시키면서
	{
		if (isPrime[i]) // 만약 소수라면
		{
			for (int j = i; j < limit; j += i) // i의 배수들을 쭉 돌면서 배수를 반전 시킴. 그러니까 이제 기본값이 1이니 인수가 하나 늘었다고 알려주는거임.
			{
				mobius[j] *= -1;
			}

			long long sqr = i * i;
			if (sqr < k * 2) // 그리고 i^2이 범위를 넘지 않았다면
			{
				for (long long j = sqr; j < limit; j += sqr) // i^2의 배수를 순회하며 0으로 바꿈.
				{
					mobius[j] = 0;
				}
			}
		}
	}


	long long left = 1;
	long long right = k * 2;

	while (left < right)
	{
		long long mid = (left + right) / 2;
		long long cnt = getSquareFreeCount(mobius, mid);
		if (cnt < k)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}

	cout << left;
}