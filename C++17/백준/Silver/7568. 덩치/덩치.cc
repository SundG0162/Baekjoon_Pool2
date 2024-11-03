#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>

using namespace std;

pair<int, int> arr[51];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0, a, b; i < n; i++)
	{
		cin >> a >> b;
		arr[i] = { a,b };
	}

	for (int i = 0; i < n; i++)
	{
		int sum = 1;
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			if (arr[i].first < arr[j].first && arr[i].second < arr[j].second)
				sum++;
		}
		cout << sum << ' ';
	}
}