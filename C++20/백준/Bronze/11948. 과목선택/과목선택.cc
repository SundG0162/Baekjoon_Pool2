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
	int a[4];
	int b[2];
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> b[0] >> b[1];

	std::sort(a, a + 4, std::greater<int>());
	std::sort(b, b + 2, std::greater<int>());

	int sum = a[0] + a[1] + a[2] + b[0];
	cout << sum;
}