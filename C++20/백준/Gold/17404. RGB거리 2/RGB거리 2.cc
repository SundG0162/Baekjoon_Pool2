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

#define RED 0
#define GREEN 1
#define BLUE 2

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> mapVector(n + 1, vector<int>(BLUE + 1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < BLUE + 1; j++)
		{
			cin >> mapVector[i][j];
		}
	}

	int min = INT32_MAX;

	for (int i = RED; i <= BLUE; i++)
	{
		vector<vector<int>> dpVector(n + 1, vector<int>(BLUE + 1,0));
		for (int j = RED; j <= BLUE; j++)
		{
			if (i == j)
				dpVector[1][j] = mapVector[1][j];
			else
				dpVector[1][j] = 1e9;
		}
		for (int j = 2; j <= n; j++)
		{
			dpVector[j][RED] = mapVector[j][RED] + std::min(dpVector[j - 1][GREEN], dpVector[j - 1][BLUE]);
			dpVector[j][GREEN] = mapVector[j][GREEN] + std::min(dpVector[j - 1][RED], dpVector[j - 1][BLUE]);
			dpVector[j][BLUE] = mapVector[j][BLUE] + std::min(dpVector[j - 1][GREEN], dpVector[j - 1][RED]);
		}
		for (int j = RED; j <= BLUE; j++)
		{
			if (i != j)
				min = std::min(dpVector[n][j], min);
		}
	}

	cout << min;
}