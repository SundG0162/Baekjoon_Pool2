#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool operator>(const pair<int, string>& p1, const pair<int, string>& p2)
{
	return p1.first < p2.first;
}

bool compare(const pair<int, string>& p1, const pair<int, string>& p2)
{
	return p1 > p2;
}

int main()
{
	int n;

	cin >> n;

	vector<pair<int, string>> vec;

	for (int i = 0; i < n; i++)
	{
		int a;
		string b;
		cin >> a >> b;
		vec.push_back(make_pair(a, b));
	}

	stable_sort(vec.begin(), vec.end(), compare);


	for (int i = 0; i < n; i++)
	{
		cout << vec[i].first << " " << vec[i].second << '\n';
	}
}