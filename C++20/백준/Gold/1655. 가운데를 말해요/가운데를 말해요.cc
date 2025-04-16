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
using std::greater;
using std::less;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))


int main()
{
	FAST_PRINT;

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> minHeap;
	priority_queue<int> maxHeap;

	for (int i = 0, input; i < n; i++)
	{
		cin >> input;
		if (maxHeap.empty())
			maxHeap.push(input);
		else if (maxHeap.top() <= input)
			minHeap.push(input);
		else
			maxHeap.push(input);

		if (maxHeap.size() > minHeap.size() + 1)
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		if (minHeap.size() > maxHeap.size())
		{
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}

		cout << maxHeap.top() << '\n';
	}
}