#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool operator<(const pair<int, int>& left, const pair<int, int>& right)
{
	if (left.second == right.second)
	{
		return left.first < right.first;
	}
	return left.second < right.second;
}

bool compare(const pair<int, int>& left, const pair<int, int>& right)
{
	return left < right;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> vec;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		vec.push_back(make_pair(x, y));
	}

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < n; i++)
	{
		cout << vec[i].first << " " << vec[i].second << '\n';
	}
}
