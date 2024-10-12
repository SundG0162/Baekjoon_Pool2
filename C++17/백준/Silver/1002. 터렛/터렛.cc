#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int dp[5001];

int main()
{
	int count;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		int sum = r1 + r2;
		int sub = abs(r1 - r2);

		int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		if (x1 == x2 && y1 == y2)
			if (r1 == r2)
				cout << -1;
			else
				cout << 0;
		else if (dist > pow(sum,2)) // 두원이 떨어져있을때
			cout << 0;
		else if (dist == pow(sum, 2)) // 두원이 한점에서 맞닿을때
			cout << 1;
		else if (pow(sub, 2) < dist && dist < pow(sum, 2)) // 두원이 교차 할때
			cout << 2;
		else if (dist == pow(sub, 2)) // 두원이 내접할때
			cout << 1;
		else if (dist < pow(sub, 2))
			cout << 0;
		
		cout << endl;
	}

	return 0;
}