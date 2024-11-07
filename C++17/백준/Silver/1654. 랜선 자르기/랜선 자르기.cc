#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int k, n;
vector<long long> v;

void binarySearch(long long min, long long max)
{
	long long mid;
	long long cnt;
	while (min <= max)
	{
		mid = (min + max) / 2;
		cnt = 0;
		for (int i = 0; i < v.size(); i++)
		{
			cnt += v[i] / mid;
		}
		if (cnt >= n)
		{
			min = mid + 1;
		}
		else
		{
			max = mid - 1;
		}
	}
	cout << max;
}

int main()
{
	cin >> k >> n;
	for (int i = 0, x; i < k; i++)
	{
		cin >> x;
		v.push_back(x);
	}

	binarySearch(1, *max_element(v.begin(), v.end()));
}