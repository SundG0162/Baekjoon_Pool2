#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int arr[1001];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	vector<int> dp(n, 1);
	vector<int> prev(n, -1);
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) 
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
		}
	}

	int index = max_element(dp.begin(), dp.end()) - dp.begin();
	cout << dp[index] << endl;
	vector<int> lis;
	for (int i = index; i != -1; i = prev[i])
	{
		lis.push_back(arr[i]);
	}
	reverse(lis.begin(), lis.end());

	for (int i = 0; i < lis.size(); i++)
	{
		cout << lis[i] << " ";
	}
}