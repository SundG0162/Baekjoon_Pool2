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

int main()
{
	int n;
	cin >> n;
	vector<int> solutionVec(n + 1);

	for (int i = 0; i < n; i++)
	{
		cin >> solutionVec[i];
	}

	int left = 0, right = n - 1;

	std::pair<int, int> minPair(solutionVec[0], solutionVec[1]);

	while (right > left)
	{
		int curMin = minPair.second + minPair.first;
		int newMin = solutionVec[right] + solutionVec[left];
		if (std::abs(newMin) < std::abs(curMin))
		{
			minPair.first = solutionVec[left];
			minPair.second = solutionVec[right];
		}
		if(newMin > 0)
		{
			right--;
		}
		else
		{
			left++;
		}
	}

	cout << minPair.first << " " << minPair.second;
}