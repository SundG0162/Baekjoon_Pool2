#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1001];

int main()
{
	int n;
	cin >> n;
	vector<int> dp(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[j]+arr[i], dp[i]);
			}
		}
	}

	cout << *max_element(dp.begin(), dp.end());
}