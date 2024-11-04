#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int c;
	cin >> c;
	for (int i = 0, x; i < c; i++)
	{
		vector<int> v;
		int n, m;
		int cnt = 0;
		cin >> n >> m;
		for (int j = 0; j < n; j++)
		{
			cin >> x;
			v.push_back(x);
		}
		while (true)
		{
			int x = v[0];
			v.erase(v.begin());
			m--;
			if (v.empty())
			{
				cnt++;
				cout << cnt << '\n';
				break;
			}
			int max = *max_element(v.begin(), v.end());
			if (max > x)
			{
				if (m == -1)
					m = v.size();
				v.push_back(x);
			}
			else
			{
				cnt++;
				if (m == -1)
				{
					cout << cnt << '\n';
					break;
				}
			}
		}
	}
}