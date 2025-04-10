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
#define A 0
#define B 1
#define C 2
#define D 3

int main()
{
	FAST_PRINT;

	int n;
	cin >> n;

	vector<vector<int>> numVec(4, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = A; j <= D; j++)
		{
			cin >> numVec[j][i];
		}
	}

	std::unordered_map<int, int> sumAB;
	sumAB.reserve(n * n);

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			int sum = numVec[A][i] + numVec[B][j];
			sumAB[sum]++;
		}
	}

	size_t count = 0;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			int sum = numVec[C][i] + numVec[D][j];
			auto it = sumAB.find(-sum);
			if (it != sumAB.end()) 
			{
				count += it->second;
			}
		}
	}

	cout << count;
}
