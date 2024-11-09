#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define PI 3.14159265358979

using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	double r;
	cin >> r;
	cout << fixed;
	cout.precision(6);
	cout << PI * (r * r) << '\n';
	cout << 2.f * (r * r);
}