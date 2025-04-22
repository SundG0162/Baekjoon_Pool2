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
using std::priority_queue;
using std::queue;
using std::deque;
using std::stack;
using std::string;
using std::pair;
using std::unordered_map;
using std::greater;
using std::less;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

int main()
{
	int n;
	cin >> n;
	vector<int> A(n + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	int sum = 0;
	for (int i = 0; i < n;)
	{
		if (A[i] > 0) //i번째를 살게 아니면 살 이유가 없음. 그냥 돈낭비
		{
			if (i + 1 < n)
			{
				if (A[i + 1] > 0)
				{
					if (i + 2 < n)
					{
						if (A[i + 2] > 0 && A[i + 1] <= A[i + 2])
						{
							sum += 2;
							A[i + 2]--;
						}
					}
					sum += 2;
					A[i + 1]--;
				}
			}
			sum += 3;
			A[i]--;
		}
		else
		{
			i++;
		}
	}
	cout << sum;
}