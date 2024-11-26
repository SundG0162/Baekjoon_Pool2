#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;
bool isEnded[100001]{ false };
pair<int, int> arr[100001];

bool compare(const pair<int, int>& first, const pair<int, int>& second)
{
	if (first.second == second.second)
	{
		return first.first < second.first;
	}
	return first.second < second.second;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0, a, b; i < n; i++)
	{
		cin >> a >> b;
		arr[i] = { a,b };
	}

	sort(arr, arr + n, compare);

	int cnt = 0;
	int startTime = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].first >= startTime)
		{
			startTime = arr[i].second;
			cnt++;
		}
	}
	cout << cnt;
}