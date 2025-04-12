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
#define BEGIN_TO_END(vec) vec.begin(), vec.end()

long long dp[101][10];

int main()
{
	FAST_PRINT;

	int t;
	cin >> t;
	while (t--)
	{
		std::map<string, int> map;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string cloth, type;
			cin >> cloth >> type;
			map[type]++;
		}

		int result = 1;

		for (const auto& pair : map)
		{
			result *= (pair.second + 1);
		}

		cout << result - 1 << '\n';
	}
}
