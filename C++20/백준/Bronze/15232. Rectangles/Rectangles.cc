#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin >> a>>b;
    while(a--)
    {
        for(int i = 0; i < b; i++)
        {
            cout << "*";
        }
        cout << '\n';
    }
}