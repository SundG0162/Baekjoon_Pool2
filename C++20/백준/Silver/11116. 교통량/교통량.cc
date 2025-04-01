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

	int left[201];
	int right[201];

	std::unordered_map<int, int> carMap;

	while (t--)
	{
		int n;
		cin >> n;

		int cnt = 0;

		for (int i = 0; i < n; i++)
		{
			cin >> left[i];
			carMap.insert({ left[i] + 500, left[i] });
		}
		for (int i = 0; i < n; i++)
		{
			cin >> right[i];
			if (carMap.contains(right[i]))
			{
				if (carMap.contains(right[i] - 1000))
				{
					cnt++;
				}
				carMap.insert({ right[i] + 500, right[i] });
			}
		}
		cout << cnt << '\n';
		carMap.clear();
	}
}
