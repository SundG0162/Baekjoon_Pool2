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
using std::deque;
using std::stack;
using std::string;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

int arr[1001];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	vector<int> maxDP(n, 1);
	vector<int> minDP(n, 1);
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				maxDP[i] = std::max(maxDP[i], maxDP[j] + 1);
			}
		}
	}
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (arr[i] > arr[j])
			{
				minDP[i] = std::max(minDP[i], minDP[j] + 1);
			}
		}
	}


	int max = 0;
	for (int i = 0; i < n; i++)
	{
		max = std::max(max, minDP[i] + maxDP[i] - 1);
	}

	cout << max;
}