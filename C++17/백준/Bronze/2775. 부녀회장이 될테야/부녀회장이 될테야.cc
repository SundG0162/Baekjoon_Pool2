#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int arr[15][15];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;

	memset(arr, 0, sizeof(arr));

	for (int i = 0; i <= 14; i++)
	{
		arr[0][i] = i;
	}

	for (int i = 0; i < t; i++)
	{
		int k, n;
		cin >> k >> n;
		for (int j = 1; j <= k; j++)
		{
			for (int l = 1; l <= n; l++)
			{
				if (arr[j][l] != 0) continue;
				arr[j][l] = arr[j][l - 1] + arr[j - 1][l];
			}
		}
		cout << arr[k][n] << '\n';
	}
}