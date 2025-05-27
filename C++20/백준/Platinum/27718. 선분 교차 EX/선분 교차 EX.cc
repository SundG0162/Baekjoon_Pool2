#include<bits/stdc++.h>

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
	bool operator==(coord other)
	{
		return x == other.x && y == other.y;
	}
};
bool isOnSegment(coord A, coord B, coord C)
{
	int minX = min(A.x, B.x);
	int maxX = max(A.x, B.x);
	int minY = min(A.y, B.y);
	int maxY = max(A.y, B.y);

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

bool isEndpoint(coord pt, line l)
{
	return pt == l.from || pt == l.to;
}

int main()
{
	FAST_PRINT;

	int n;
	cin >> n;
	vector<line> lineVec(n + 1);

	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		lineVec[i] = { x1,y1,x2,y2 };
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			line l1 = lineVec[i];
			line l2 = lineVec[j];
			bool crossed = isCrossed(l1, l2);

			if (crossed)
			{
				long double A1 = l1.to.y - l1.from.y;
				long double B1 = l1.from.x - l1.to.x;
				long double C1 = A1 * l1.from.x + B1 * l1.from.y;

				long double A2 = l2.to.y - l2.from.y;
				long double B2 = l2.from.x - l2.to.x;
				long double C2 = A2 * l2.from.x + B2 * l2.from.y;

				long double det = A1 * B2 - A2 * B1;

				if (det != 0)
				{
					long double ix = (B2 * C1 - B1 * C2) / det;
					long double iy = (A1 * C2 - A2 * C1) / det;

					if (fabsl(ix - round(ix)) <= LDBL_EPSILON && fabsl(iy - round(iy)) <= LDBL_EPSILON)
					{
						coord crossPt = { (long long)round(ix), (long long)round(iy) };
						if (isEndpoint(crossPt, l1) || isEndpoint(crossPt, l2))
							cout << 1;
						else
							cout << 2;
					}
					else
						cout << 2;
				}
				else
				{
					vector<coord> candidates = { l1.from, l1.to, l2.from, l2.to };
					set<pair<long long, long long>> pts;
					for (auto& p : candidates)
					{
						if (l1.isOnRange(p) && l2.isOnRange(p))
						{
							pts.emplace(p.x, p.y);
						}
					}
					if (pts.size() == 1)
					{
						cout << 1;
					}
					else
					{
						cout << 3;
					}
				}
			}
			else
				cout << 0;
		}
		cout << '\n';
	}
}