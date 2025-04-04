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

int minDP[2][3];
int maxDP[2][3];
int main()
{
	int n;
	cin >> n;

	int map[2][3];

	for (int i = 0; i < n; i++)
	{
		int idx = i % 2;
		for (int j = 0; j < 3; j++)
		{
			cin >> map[idx][j];
		}
		if (i == 0)
		{
			for (int i = 0; i < 3; i++)
			{
				minDP[0][i] = map[0][i];
				maxDP[0][i] = map[0][i];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				minDP[idx][i] = INT32_MAX;
			}
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (std::abs(i - j) > 1)
						continue;
					minDP[idx][i] = std::min(minDP[!idx][j] + map[idx][i], minDP[idx][i]);
					maxDP[idx][i] = std::max(maxDP[!idx][j] + map[idx][i], maxDP[idx][i]);
				}
			}
		}
	}

	int min = INT32_MAX, max = 0;

	int idx = (n - 1) % 2;
	for (int i = 0; i < 3; i++)
	{
		min = std::min(minDP[idx][i], min);
		max = std::max(maxDP[idx][i], max);
	}

	cout << max << " " << min;
}