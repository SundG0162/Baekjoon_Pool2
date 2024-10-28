#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int arr[10000001];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		v.push_back(arr[i]);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < n; i++)
	{
		int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
		cout << idx << " ";
	}
}