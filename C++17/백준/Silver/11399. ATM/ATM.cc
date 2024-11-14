#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	int n;
	cin >> n;
	int sum = 0;
	int sum2 = 0;
	for (int i = 0, x; i < n; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	for (int i = 0; i < n; i++)
	{
		auto min = min_element(v.begin(), v.end());
		sum += *min;
		sum2 += sum;
		v.erase(min);
	}
	cout << sum2;
}