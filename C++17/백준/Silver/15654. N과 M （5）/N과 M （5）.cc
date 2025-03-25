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
vector<int> nVector;
vector<int> sequence;

void N_and_M()
{
	if (sequence.size() == m)
	{
		for (int i = 0; i < sequence.size(); i++)
			cout << sequence[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = 0; i < nVector.size(); i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			sequence.push_back(nVector[i]);
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
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		nVector.push_back(input);
	}
	std::sort(nVector.begin(), nVector.end());
	N_and_M();
}