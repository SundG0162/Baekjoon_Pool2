#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::string;

int arr[100001];

int main()
{
	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int start = 0, end = 0, sum = arr[0], min = INT32_MAX;
	while (true)
	{
		if (sum >= s)
		{
			int l = (end - start + 1);
			if (l < min)
			{
				min = l;
			}
			sum -= arr[start];
			start++;
		}
		if (sum < s)
		{
			end++;
			sum += arr[end];
		}
		if (end == n || start == n)
		{
			break;
		}
	}
	if (min == INT32_MAX)
		cout << 0;
	else
		cout << min;
}