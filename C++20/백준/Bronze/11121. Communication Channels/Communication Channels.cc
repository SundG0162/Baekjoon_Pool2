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
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        a == b ? cout << "OK\n" : cout << "ERROR\n";
    }
}