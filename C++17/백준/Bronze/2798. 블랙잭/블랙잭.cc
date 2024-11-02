#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int card[101];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> card[i];

	int closest = INT32_MAX;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			for (int k = 0; k < n; k++)
			{
				if (j == k || i == k) continue;
				if (closest == m)
				{
					cout << closest;
					return 0;
				}
				int sum = card[i] + card[j] + card[k];
				if (sum > m)continue;
				int diff1 = abs(sum - m);
				int diff2 = abs(closest - m);
				if (diff1 < diff2)
					closest = sum;
			}
		}
	}
	cout << closest;
}