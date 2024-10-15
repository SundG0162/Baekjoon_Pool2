#include <iostream>

using namespace std;

bool arr[1000001];
int main()
{
	int m, n;
	cin >> m >> n;

	arr[0] = arr[1] = true;

	for (int i = 2; i * i <= n; ++i)
	{
		if (arr[i]) continue;
		for (int j = 2; i * j <= n; j++)
		{
			arr[i * j] = true;
		}
	}

	for (int i = m; i <= n; ++i)
		if (!arr[i])
			cout << i << "\n";
}
