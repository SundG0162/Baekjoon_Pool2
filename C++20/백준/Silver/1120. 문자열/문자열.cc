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
	string str1, str2;
	cin >> str1 >> str2;

	int minCnt = INT32_MAX;
	for (int i = 0; i <= str2.size() - str1.size(); i++)
	{
		int cnt = 0;
		for (int j = i; j < i + str1.size(); j++)
		{
			if (str1[j - i] != str2[j])
			{
				cnt++;
			}
		}
		minCnt = std::min(minCnt, cnt);
	}
	cout << minCnt;
}