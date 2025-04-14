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
using std::queue;
using std::deque;
using std::stack;
using std::string;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

int main()
{
	FAST_PRINT;

	int n;
	cin >> n;

	vector<int> seqVec(n + 1);

	for (int i = 0; i < n; i++)
	{
		cin >> seqVec[i];
	}

	vector<int> lis;
	vector<int> prev(n + 1, -1);

	lis.push_back(0);

	for (int i = 1; i < n; i++)
	{
		int left = 0, right = lis.size(), middle;
		while (left < right)
		{
			middle = left + (right - left) / 2;
			if (seqVec[i] < seqVec[lis[middle]])
				right = middle;
			else if (seqVec[i] > seqVec[lis[middle]])
				left = middle + 1;
			else
			{
				left = middle;
				break;
			}
		}
		if (left == lis.size())
			lis.push_back(i);
		else
			lis[left] = i;

		if (prev[lis[left]] == -1 && left != 0)
			prev[lis[left]] = lis[left-1];
	}

	cout << lis.size() << '\n';

	vector<int> elementVec;
	int cur = lis.back();
	while (cur != -1) 
	{
		elementVec.push_back(cur);
		cur = prev[cur];
	}

	for (int i = elementVec.size() -1 ; i >= 0; i--)
	{
		cout << seqVec[elementVec[i]] << ' ';
	}

}
