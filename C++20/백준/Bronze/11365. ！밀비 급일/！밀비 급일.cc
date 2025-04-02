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
	while (true)
	{
		std::getline(cin, input);

		if (input == "END")
			break;

		std::reverse(input.begin(), input.end());
		cout << input << '\n';
	}
}