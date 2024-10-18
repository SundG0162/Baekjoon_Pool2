#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n;

string board[26];
int visited[26][26]{ {{0}} };
queue<pair<int, int>> q;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };


int BFS(int x, int y)
{
	int count = 0;
	if (board[x][y] == '0' || visited[x][y] == 1) return 0;
	if (board[x][y] == '1' && visited[x][y] == 0)
		count++;
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (board[nx][ny] == '1' && visited[nx][ny] == 0)
			{
				visited[nx][ny] = 1;
				count++;
				q.push({ nx,ny });
			}
		}
	}
	return count;
}

int main()
{
	cin >> n;
	vector<int> counts;
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int count = BFS(i,j);
			if (count != 0)
				counts.push_back(count);
		}
	}

	sort(counts.begin(), counts.end());
	cout << counts.size() << '\n';
	for (int i = 0; i < counts.size(); i++)
	{
		cout << counts[i] << '\n';
	}
}