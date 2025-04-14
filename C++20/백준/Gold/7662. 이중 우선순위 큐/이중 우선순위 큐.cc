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
using std::priority_queue;
using std::deque;
using std::stack;
using std::string;

#define ll long long

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

void solve()
{
	std::unordered_map<int, int> numCheckMap;

	priority_queue<ll, vector<ll>, std::greater<ll>> greaterQ;
	priority_queue<ll, vector<ll>, std::less<ll>> lessQ;

	int k;
	cin >> k;
	numCheckMap.reserve(k + 1);

	int inserted = 0;
	int deleted = 0;

	for (int i = 0; i < k; i++)
	{
		char cmd;
		ll n;
		cin >> cmd >> n;
		if (cmd == 'D')
		{
			if (inserted - deleted <= 0)
				continue;
			if (n == -1)
			{
				while (true)
				{
					int top = greaterQ.top();
					if (numCheckMap[top] == 0)
						greaterQ.pop();
					else
						break;
				}
				numCheckMap[greaterQ.top()]--;
				greaterQ.pop();
			}
			else if (n == 1)
			{
				while (true)
				{
					int top = lessQ.top();
					if (numCheckMap[top] == 0)
						lessQ.pop();
					else
						break;
				}
				numCheckMap[lessQ.top()]--;
				lessQ.pop();
			}
			deleted++;
		}
		else if (cmd == 'I')
		{
			numCheckMap[n]++;
			greaterQ.push(n);
			lessQ.push(n);
			inserted++;
		}
	}

	if (inserted - deleted <= 0)
		cout << "EMPTY" << '\n';
	else
	{
		while (true)
		{
			int top = lessQ.top();
			if (numCheckMap[top] == 0)
				lessQ.pop();
			else
				break;
		}
		while (true)
		{
			int top = greaterQ.top();
			if (numCheckMap[top] == 0)
				greaterQ.pop();
			else
				break;
		}
		cout << lessQ.top() << ' ' << greaterQ.top() << '\n';
	}
}

int main()
{
	FAST_PRINT;

	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}
