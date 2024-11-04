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
	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	vector<int> v;
	for (int i = 0, x; i < n; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int threshold = round((float)n / 100.f * 15.f);
	int m = n;
	m -= threshold * 2;
	int sum = 0;
	for (int i = threshold; i < threshold + m; i++)
	{
		sum += v[i];
	}
	cout << round((float)sum / (float)m);
}