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
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> a, b;

	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		a.push_back(input);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		b.push_back(input);
	}

	int la = 0, lb = 0;
	for (int i = 0; i < m + n; i++)
	{
		if (la >= n)
		{
			cout << b[lb] << ' ';
			lb++;
			continue;
		}
		else if (lb >= m)
		{
			cout << a[la] << ' ';
			la++;
			continue;
		}
		if (a[la] <= b[lb])
		{
			cout << a[la] << ' ';
			la++;
		}
		else if (b[lb] < a[la])
		{
			cout << b[lb] << ' ';
			lb++;
		}
	}
}
