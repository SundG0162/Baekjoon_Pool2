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
	long long n, b, c;
	cin >> n >> b >> c;
	vector<long long> A(n + 2, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	long long sum = 0;
	if (c >= b) //묶음 구매가 더 비쌈. 왜 삼?
	{
		for (int i = 0; i < n; i++)
		{
			sum += A[i] * b;
			A[i] = 0;
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (A[i] > 0)
			{
				if (A[i + 1] > A[i + 2])
				{
					long long yi = std::min(A[i], A[i + 1] - A[i + 2]);
					A[i] -= yi;
					A[i + 1] -= yi;
					sum += yi * (b + c);
				}

				long long sam = std::min({ A[i],A[i + 1],A[i + 2] });
				A[i] -= sam;
				A[i + 1] -= sam;
				A[i + 2] -= sam;
				sum += sam * (b + c + c);

				long long il = A[i];
				A[i] = 0;
				sum += il * b;
			}
		}
	}
	cout << sum;
}