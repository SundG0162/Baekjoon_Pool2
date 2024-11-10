#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define PI 3.14159265358979

using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> v;
	int n;
	cin >> n;
	for (int i = 0, x; i < n; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}
}