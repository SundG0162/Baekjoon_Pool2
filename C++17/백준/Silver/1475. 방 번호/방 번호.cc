#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int dp[501];
int main() 
{
    int n;
    cin >> n;
    int num[10]{ {0} };
    while (n != 0)
    {
        int mod = n % 10;
        num[mod]++;
        n /= 10;
    }
    int max = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i == 6 || i == 9)
        {
            continue;
        }
        else
        {
            if (max < num[i])
            {
                max = num[i];
            }
        }
    }
    int m = num[6] + num[9];
    m = m / 2 + (m % 2);
    max = max > m ? max : m;
    cout << max;
    return 0;
}