#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<deque>
#include<stack>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<map>
#include<unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;
using std::queue;
using std::deque;
using std::stack;
using std::string;
using std::pair;
using std::unordered_map;
using std::greater;
using std::less;

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
bool isOnSegment(coord A, coord B, coord C)
{
	int minX = std::min(A.x, B.x);
	int maxX = std::max(A.x, B.x);
	int minY = std::min(A.y, B.y);
	int maxY = std::max(A.y, B.y);

	return minX <= C.x && C.x <= maxX &&
		minY <= C.y && C.y <= maxY;
}

struct line
{
	coord from, to;

	void sort()
	{
		if (from.x > to.x || (from.x == to.x && from.y > to.y))
		{
			coord temp = from;
			from = to;
			to = temp;
		}
	}

	bool isOnRange(coord a)
	{
		return isOnSegment(from, to, a);
	}
};

int ccw(const coord& a, const coord& b, const coord& c)
{
	long long cross = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (cross > 0) return  1;
	if (cross < 0) return -1;
	return 0;
}


bool isCrossed(line l1, line l2)
{
	int ccw1 = ccw(l1.from, l1.to, l2.from);
	int ccw2 = ccw(l1.from, l1.to, l2.to);
	int ccw3 = ccw(l2.from, l2.to, l1.from);
	int ccw4 = ccw(l2.from, l2.to, l1.to);

	if (ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0)
		return true;

	if (ccw1 == 0 && l1.isOnRange(l2.from))
		return true;
	if (ccw2 == 0 && l1.isOnRange(l2.to))
		return true;
	if (ccw3 == 0 && l2.isOnRange(l1.from))
		return true;
	if (ccw4 == 0 && l2.isOnRange(l1.to))
		return true;

	if (ccw1 == 0 && ccw2 == 0 && ccw3 == 0 && ccw4 == 0)
	{
		l1.sort();
		l2.sort();
		if (l2.to >= l1.from && l1.to >= l2.from)
			return true;
	}
	return false;
}

int main()
{
	FAST_PRINT;

	line l1, l2;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	l1.from = { x1,y1 };
	l1.to = { x2,y2 };
	cin >> x1 >> y1 >> x2 >> y2;
	l2.from = { x1,y1 };
	l2.to = { x2,y2 };

	cout << isCrossed(l1, l2);
}

