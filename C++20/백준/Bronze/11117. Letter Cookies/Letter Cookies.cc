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

int available[26];

bool check(string input) 
{
    int temp[26];
    memcpy(temp, available, sizeof(available));

    for (char c : input) 
    {
        if (temp[c - 'A'] <= 0) 
        {
            return false;
        }
        temp[c - 'A']--;
    }
    return true;
}

int main() 
{
    int t;
    cin >> t;

    while (t--) 
    {
        memset(available, 0, sizeof(available));

        string input;
        cin >> input;

        for (char c : input) 
        {
            available[c - 'A']++;
        }

        int w;
        cin >> w;

        while (w--) 
        {
            cin >> input;

            if (check(input))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}