#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int>> vec;
bool visited[100001];
int c = 0;

void dfs(int r)
{
	visited[r] = true;

	c++;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].first == r && !visited[vec[i].second])
		{
			dfs(vec[i].second);
		}
		else if (vec[i].second == r && !visited[vec[i].first])
		{
			dfs(vec[i].first);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, r;
	r = 1;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		vec.push_back({ u,v });
	}

	sort(vec.begin(), vec.end());

	dfs(r);

	cout << c - 1;
}