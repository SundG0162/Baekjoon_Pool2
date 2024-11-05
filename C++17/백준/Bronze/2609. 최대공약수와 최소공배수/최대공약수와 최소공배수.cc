#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int a, b;
	cin >> a >> b;
	int c = a, d = b;
	int temp = 0;
	while (d != 0) {
		temp = c % d;
		c = d;
		d = temp;
	}
	cout << c << '\n';
	cout << (a * b) / c;
}