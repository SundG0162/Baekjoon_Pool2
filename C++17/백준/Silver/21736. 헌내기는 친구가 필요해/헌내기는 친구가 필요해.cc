#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::stack;
using std::string;

bool visited[601][601];

int main()
{
	int n, m;
	cin >> n >> m;

	memset(visited, false, sizeof(visited));
	string map[601];

	std::pair<int, int> dPos(-1, -1);

	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
		if (dPos.first == -1)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 'I')
				{
					dPos = { j,i };
					break;
				}
			}
		}
	}


	int cnt = 0;

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	std::queue<std::pair<int, int>> q;
	q.push(dPos);
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int mx = cx + dx[i];
			int my = cy + dy[i];
			if (visited[my][mx])
				continue;
			visited[my][mx] = true;
			if (mx < 0 || mx >= m || my < 0 || my >= n)
				continue;
			if (map[my][mx] == 'X')
				continue;
			if (map[my][mx] == 'P')
				cnt++;
			q.push({ mx,my });
		}
	}
	if (cnt == 0)
		cout << "TT";
	else
		cout << cnt;
}