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

int main()
{
	int n, k;
	cin >> n >> k;

	vector<bool> numVec(n + 1, true);

	for (int i = 2; i <= n; i++)
	{
		for (int j = i; j <= n; j += i)
		{
			if (numVec[j])
			{
				numVec[j] = false;
				k--;
				if (k <= 0)
				{
					cout << j;
					return 0;
				}
			}
		}
	}
}