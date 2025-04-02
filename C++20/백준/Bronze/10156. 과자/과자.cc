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
	int k, n, m;
	cin >> k >> n >> m;

	int price = k * n;
	if (price > m)
		cout << price - m;
	else
		cout << 0;
}