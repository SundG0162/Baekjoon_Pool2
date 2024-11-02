#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;

	cout << n / 5 + n / 25 + n / 125;
}