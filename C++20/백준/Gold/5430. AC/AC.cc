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

deque<int> parseArray(const string& input)
{
	deque<int> result;

	string fixed = input.substr(1, input.size() - 2);

	if (fixed.empty())
		return result;

	std::stringstream ss(fixed);
	string num;

	while (std::getline(ss, num, ','))
	{
		result.push_back(std::stoi(num));
	}

	return result;
}

void solve()
{
	string commands;
	int l;
	string arr;
	cin >> commands >> l >> arr;

	deque<int> numDeq = parseArray(arr);

	bool isReversed = false;

	for (char cmd : commands)
	{
		switch (cmd)
		{
		case 'R':
		{
			isReversed = !isReversed;
		}
		break;
		case 'D':
		{
			if (numDeq.empty())
			{
				cout << "error";
				return;
			}
			if (isReversed)
				numDeq.pop_back();
			else
				numDeq.pop_front();
		}
		break;
		}
	}

	cout << '[';
	if (isReversed)
	{
		for (int i = numDeq.size() - 1; i >= 0; i--)
		{
			cout << numDeq[i];
			if (i != 0)
			{
				cout << ',';
			}
		}
	}
	else
	{
		for (int i = 0; i < numDeq.size(); i++)
		{
			cout << numDeq[i];
			if (i != numDeq.size() - 1)
			{
				cout << ',';
			}
		}
	}
	
	cout << ']';
}

int main()
{
	FAST_PRINT;

	int t;
	cin >> t;

	while (t--)
	{
		solve();
		cout << '\n';
	}
}
