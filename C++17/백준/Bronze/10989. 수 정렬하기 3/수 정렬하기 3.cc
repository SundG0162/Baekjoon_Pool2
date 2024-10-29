#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int arr[10001];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int maxValue = 0;
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        maxValue = max(maxValue, x);
        arr[x]++;
    }

    for (int i = 1; i <= maxValue; ++i)
    {
        if (arr[i] == 0) continue;
        cout << i << '\n';
        arr[i]--;
        i--;
    }
}