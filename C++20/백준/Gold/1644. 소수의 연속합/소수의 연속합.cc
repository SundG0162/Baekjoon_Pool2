#include<iostream>
#include<string>
#include<cstring>
#include<queue>
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
using std::stack;
using std::string;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	FAST_PRINT;

	int n;
	cin >> n;

	vector<int> primeVec;

	vector<bool> isPrime(n + 1, true);

	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i * i <= n; i++)
	{
		for (int j = i * 2; j <= n; j += i)
		{
			isPrime[j] = false;
		}
	}

	for (int i = 0; i < isPrime.size(); i++)
	{
		if (isPrime[i])
			primeVec.push_back(i);
	}

	int cnt = 0;
	for (int left = 0; left <= n; left++)
	{
		int right = left;
		while (right < primeVec.size())
		{
			int sum = 0;
			for (int i = left; i <= right; i++)
			{
				sum += primeVec[i];
			}
			if (sum == n)
				cnt++;
			if (sum > n)
				break;
			right++;
		}
	}

	cout << cnt;
}