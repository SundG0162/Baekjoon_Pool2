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
	string str;
	string bomb;
	cin >> str >> bomb;

	stack<char> answer;

	for (int i = 0; i < str.size(); i++)
	{
		answer.push(str[i]);

		if (answer.size() >= bomb.size())
		{
			string bombChecker = "";
			bombChecker.reserve(bomb.size());

			for (int i = 0; i < bomb.size(); i++)
			{
				bombChecker += answer.top();
				answer.pop();
			}

			std::reverse(bombChecker.begin(), bombChecker.end());
			if (bombChecker != bomb)
			{
				for (int i = 0; i < bombChecker.size(); i++)
				{
					answer.push(bombChecker[i]);
				}
			}
		}
	}

	string ans;
	ans.reserve(answer.size());

	while (!answer.empty())
	{
		ans += answer.top();
		answer.pop();
	}
	std::reverse(ans.begin(), ans.end());

	ans == "" ? cout << "FRULA" : cout << ans;
}