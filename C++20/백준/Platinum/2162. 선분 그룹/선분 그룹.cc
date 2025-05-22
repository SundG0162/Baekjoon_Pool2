#include<bits/stdc++.h>

using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))
#define INF 1e9

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
	long long minX = std::min(A.x, B.x);
	long long maxX = std::max(A.x, B.x);
	long long minY = std::min(A.y, B.y);
	long long maxY = std::max(A.y, B.y);
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
	bool operator==(line other)
	{
		return from == other.from && to == other.to;
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

vector<int> parent, groupSize;

int find(int x)
{
	if (parent[x] != x)
		parent[x] = find(parent[x]);
	return parent[x];
}

void unite(int x, int y)
{
	int rootX = find(x);
	int rootY = find(y);
	if (rootX != rootY)
	{
		if (groupSize[rootX] < groupSize[rootY])
			swap(rootX, rootY);
		parent[rootY] = rootX;
		groupSize[rootX] += groupSize[rootY];
	}
}
int main()
{
	FAST_PRINT;
	int n;
	cin >> n;
	vector<line> lineVec;
	parent.resize(n);
	groupSize.resize(n, 1);
	for (int i = 0; i < n; i++)
		parent[i] = i;

	for (int i = 0, x1, y1, x2, y2; i < n; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		line curLine = { x1,y1,x2,y2 };

		for (int j = 0; j < lineVec.size(); j++)
		{
			if (isCrossed(curLine, lineVec[j]))
			{
				unite(i, j);
			}
		}
		lineVec.push_back(curLine);
	}

	int groupCount = 0;
	int biggest = 0;
	vector<bool> visited(n, false);

	for (int i = 0; i < n; i++)
	{
		int root = find(i);
		if (!visited[root])
		{
			visited[root] = true;
			groupCount++;
			biggest = max(biggest, groupSize[root]);
		}
	}

	cout << groupCount << '\n' << biggest;
}