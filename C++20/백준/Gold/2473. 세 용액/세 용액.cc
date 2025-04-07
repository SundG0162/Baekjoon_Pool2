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

struct triple
{
	long long first;
	long long second;
	long long third;

	long long sum()
	{
		return first + second + third;
	}

	void sort()
	{
		int temp;
		if (first > second)
		{
			temp = first;
			first = second;
			second = temp;
		}
		if (second > third)
		{
			temp = second;
			second = third;
			third = temp;
		}
		if (first > second)
		{
			temp = first;
			first = second;
			second = temp;
		}
	}
};

int n;
long long solutions[5001];

triple minPair;


triple checkSolutions(int middle)
{
	int left = 0;
	int right = n - 1;
	triple pair(1000000001, 1000000001, 1000000001);
	while (right > left)
	{
		if (left == middle)
		{
			left++;
			continue;
		}
		if (right == middle)
		{
			right--;
			continue;
		}

		long long curMin = pair.sum();
		long long newMin = solutions[middle] + solutions[left] + solutions[right];

		if (std::abs(newMin) < std::abs(curMin))
		{
			pair = { solutions[middle],solutions[left],solutions[right] };
		}

		if (newMin > 0)
		{
			right--;
		}
		else if (newMin == 0)
		{
			break;
		}
		else
		{
			left++;
		}
	}

	return pair;
}

int main()
{
	FAST_PRINT;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> solutions[i];
	}

	std::sort(solutions, solutions + n, std::less<long long>());

	minPair = { solutions[0], solutions[1], solutions[2] };


	for (int i = 0; i < n; i++)
	{
		triple pair = checkSolutions(i);

		long long newMin = pair.sum();
		long long curMin = minPair.sum();
		if (std::abs(newMin) < std::abs(curMin))
		{
			minPair = pair;
		}
	}

	minPair.sort();

	cout << minPair.first << " " << minPair.second << " " << minPair.third;
}