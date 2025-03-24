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

int n, m;
bool visited[9];

vector<int> sequence;

void N_and_M()
{
	if (sequence.size() == m)
	{
		for (int i = 0; i < sequence.size(); i++)
			cout << sequence[i] << " ";
		cout << '\n';
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			if (!sequence.empty() && sequence.back() >= i)
				continue;
			visited[i] = true;
			sequence.push_back(i);
			N_and_M();
			sequence.pop_back();
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;
	memset(visited, false, sizeof(visited));
	N_and_M();
}