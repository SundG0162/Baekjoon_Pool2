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

	for (int i = 1; i <= n; i++)
	{
		if (!sequence.empty() && sequence.back() > i)
			continue;
		sequence.push_back(i);
		N_and_M();
		sequence.pop_back();
	}
}

int main()
{
	cin >> n >> m;
	N_and_M();
}