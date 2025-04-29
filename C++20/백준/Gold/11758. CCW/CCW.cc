#include <bits/stdc++.h>
using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

struct coord
{
	long long x, y;

	bool operator>(const coord& other)
	{
		if (x == other.x)
		{
			return y > other.y;
		}
		return x > other.x;
	}
	bool operator>=(const coord& other)
	{
		if (x == other.x)
		{
			return y >= other.y;
		}
		return x >= other.x;
	}



};

int ccw(const coord& a, const coord& b, const coord& c)
{
	long long cross = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (cross > 0) return  1;
	if (cross < 0) return -1;
	return 0;
}



int main()
{
	FAST_PRINT;

	coord c1, c2, c3;
	cin >> c1.x >> c1.y >> c2.x >> c2.y >> c3.x >> c3.y;

	cout << ccw(c1, c2, c3);

}