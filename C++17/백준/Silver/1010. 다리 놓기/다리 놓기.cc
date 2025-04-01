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
	int t;
	cin >> t;
	int n, m;
	for (int i = 0; i < t; i++)
	{
		long long answer = 1;
		cin >> n >> m;

		int r = 1;
		for (int j = m; j > m - n; j--)
		{
			answer *= j;
			answer /= r;
			r++;
		}

		cout << answer << '\n';
	}
}