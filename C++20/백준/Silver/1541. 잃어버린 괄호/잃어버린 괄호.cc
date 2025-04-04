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
	string input;
	cin >> input;

	std::istringstream sub_ss(input);

	vector<std::pair<int, int>> resultVec;

	bool isFirst = true;
	string express, value;
	while (std::getline(sub_ss, express, '-'))
	{
		int result = 0;
		std::istringstream add_ss(express);
		while (std::getline(add_ss, value, '+'))
		{
			result += std::stoi(value);
		}
		int multiplier = isFirst ? 1 : -1;
		isFirst = false;
		resultVec.push_back({ multiplier, result });
	}

	int answer = 0;
	for (auto& pair : resultVec)
	{
		answer += pair.first * pair.second;
	}

	cout << answer;
}