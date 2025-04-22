#include <bits/stdc++.h>
using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

typedef pair<int, int> coord;

int r, c;

coord dir[4]{ {0,-1 },{-1,0}, {0,1} ,{ 1, 0 } };

struct meltInfo
{
	coord cur;
	int count = 0;
};

bool isOutOfRange(const coord& coord)
{
	return coord.first < 0 || coord.second < 0 || coord.first >= c || coord.second >= r;
}

bool isWater(char c)
{
	return c == '.' || c == 'L';
}

int encode(int x, int y)
{
	return x * c + y;
}

inline int encode(const coord& p) 
{
	return p.second * c + p.first;
}

int findParent(vector<int>& parentMap, int encoded)
{
	if (parentMap[encoded] == encoded)
		return encoded;
	return parentMap[encoded] = findParent(parentMap, parentMap[encoded]);
}

void unionParent(vector<int>& parentMap, int a, int b)
{
	int rootA = findParent(parentMap, a);
	int rootB = findParent(parentMap, b);
	if (rootA != rootB)
		parentMap[rootB] = rootA;
}

int main()
{
	cin >> r >> c;

	vector<vector<char>> mapVector(r, vector<char>(c));

	vector<int> parent(r * c, -1);
	parent.reserve(r * c);

	coord swan1{ -1,-1 }, swan2;

	queue<meltInfo> meltQueue;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> mapVector[i][j];
			if (isWater(mapVector[i][j]))
			{
				if (mapVector[i][j] == 'L')
				{
					if (swan1.first == -1)
						swan1 = { j,i };
					else
						swan2 = { j,i };
				}
				coord c{ j,i };
				int encodedC = encode(c);
				parent[encodedC] = encodedC;
				meltQueue.push({ c,0 });
				for (int i = 0; i < 4; i++)
				{
					coord temp = { c.first + dir[i].first, c.second + dir[i].second };
					if (!isOutOfRange(temp))
					{
						if (isWater(mapVector[temp.second][temp.first]))
						{
							int neighbor = encode(temp);
							unionParent(parent, encodedC, neighbor);
						}
					}
				}
			}
		}
	}

	if (findParent(parent, encode(swan1)) == findParent(parent, encode(swan2)))
	{
		cout << 0;
		return 0;
	}
	while (!meltQueue.empty())
	{
		meltInfo info = meltQueue.front();
		mapVector[info.cur.second][info.cur.first] = '.';
		meltQueue.pop();

		for (int i = 0; i < 4; i++)
		{
			meltInfo tempInfo = info;
			tempInfo.cur.first += dir[i].first;
			tempInfo.cur.second += dir[i].second;
			if (!isOutOfRange(tempInfo.cur))
			{
				char c = mapVector[tempInfo.cur.second][tempInfo.cur.first];
				if (!isWater(c))
				{
					int encoded = encode(tempInfo.cur);
					if (parent[encoded] == -1) // parent가 없다 == 아직 탐색하지 않았다
					{
						parent[encoded] = encoded;
						mapVector[tempInfo.cur.second][tempInfo.cur.first] = '-';
						tempInfo.count++;
						meltQueue.push(tempInfo);
						unionParent(parent, encoded, encode(info.cur));
					}
				}
				else
				{
					unionParent(parent, encode(info.cur), encode(tempInfo.cur));


				}
			}
		}
		int parent1 = findParent(parent, encode(swan1));
		int parent2 = findParent(parent, encode(swan2));
		if (parent1 == parent2)
		{
			cout << info.count;
			return 0;
		}
	}
}