#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::string;

int main()
{
	int map[501][501];

	int highest = 0, lowest = 256;
	int height[257];
	memset(height, 0, sizeof(height));

	int n, m, b;
	cin >> n >> m >> b;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int input;
			cin >> input;
			map[i][j] = input;
			height[input]++;
			if (input > highest)
				highest = input;
			if (input < lowest)
				lowest = input;
		}
	}

	int highestHeight = 0;
	int minTime = INT32_MAX;

	for (int i = lowest; i <= highest; i++)
	{
		int time = 0;
		int curBlock = b;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (map[j][k] < i)
				{
					int count = i - map[j][k];
					time += count;
					curBlock -= count;
				}
				else if (map[j][k] > i)
				{
					int count = map[j][k] - i;
					time += count * 2;
					curBlock += count;
				}
			}
		}
		if (curBlock < 0)
			continue;
		if (time <= minTime)
		{
			highestHeight = i;
			minTime = time;
		}
	}

	cout << minTime << " " << highestHeight;

	return 0;
}