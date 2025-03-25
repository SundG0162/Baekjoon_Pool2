#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::stack;
using std::string;

int main()
{
	long long a, b, c;
	cin >> a >> b >> c;

    long long answer = 1;
    a %= c; 

    while (b > 0)
    {
        if (b & 1)
        {
            answer = (answer * a) % c;
        }
        a = (a * a) % c;
        b >>= 1;
    }

	cout << answer % c;
}