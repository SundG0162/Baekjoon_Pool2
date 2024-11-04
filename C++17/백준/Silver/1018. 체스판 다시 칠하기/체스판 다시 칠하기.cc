#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>

using namespace std;

string wB[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

string bB[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

string map[51];

int whiteFill(int x, int y)
{
	int cnt = 0;
	for (int i = y; i < y + 8; i++)
	{
		for (int j = x; j < x + 8; j++)
		{
			if (map[i][j] != wB[i - y][j - x])
				cnt++;
		}
	}
	return cnt;
}

int blackFill(int x, int y)
{
	int cnt = 0;
	for (int i = y; i < y + 8; i++)
	{
		for (int j = x; j < x + 8; j++)
		{
			if (map[i][j] != bB[i - y][j - x])
				cnt++;
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}

	int minCnt = INT32_MAX;
	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			int wC = whiteFill(j, i);
			int bC = blackFill(j, i);

			minCnt = min(minCnt, min(wC, bC));
		}
	}
	cout << minCnt;
}