#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
vector<int> nums, nums2;
int cnt[8001];
int n, cnt2;
double sum;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	nums = vector<int>(n);
	for (int& num : nums)
	{
		cin >> num;
		sum += num;
		cnt[num + 4000]++;
	}

	sort(nums.begin(), nums.end());

	for (int i = 0; i < 8001; ++i)
	{
		if (cnt[i] > cnt2)
		{
			nums2.clear();
			cnt2 = cnt[i];
			nums2.push_back(i - 4000);
		}
		else if (cnt[i] == cnt2)
		{
			nums2.push_back(i - 4000);
		}
	}

	float r = round(sum / n);
	if (r == -0)
		cout << 0 << '\n';
	else
		cout << r << '\n';

	cout << nums[n / 2] << '\n';
	if (nums2.size() == 1)
	{
		cout << nums2[0] << '\n';
	}
	else
	{
		cout << nums2[1] << '\n';
	}
	cout << nums.back() - nums.front();
	return 0;
}