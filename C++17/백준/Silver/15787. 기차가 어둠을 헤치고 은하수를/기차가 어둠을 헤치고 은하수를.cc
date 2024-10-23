#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int arr[100001];
map<int, int> mapp;

bool hasCustomer(int num, int index)
{
	return (num & (1 << index)) > 0;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;

	int num, i, x;
	for (int j = 0; j < m; j++)
	{
		cin >> num >> i;
		i--;
		switch (num)
		{
		case 1:
		{
			cin >> x;
			arr[i] |= (1 << x);
		}
		break;
		case 2:
		{
			cin >> x;
			arr[i] &= ~(1 << x);
		}
		break;
		case 3:
		{
			arr[i] <<= 1;
			arr[i] &= ((1 << 21) - 1);
		}
		break;
		case 4:
		{
			arr[i] >>= 1;
			arr[i] &= ~1;
		}
		break;
		}
	}

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (mapp[arr[i]]++)continue;
		count++;
	}
	cout << count;
}