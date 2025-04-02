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
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		int input;
		cin >> input;
		if (input == n)
			cnt++;
	}
	cout << cnt;
}