#include<iostream>
#include<string>
#include<cstring>
#include<queue>
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
using std::queue;
using std::stack;
using std::string;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()


bool isFruitTypeValid(int* curFruits)
{
	int cnt = 0;
	for (int i = 0; i < 10; i++)
	{
		if (curFruits[i])
			cnt++;
		if (cnt > 2)
			return false;
	}
	return true;
}

int main()
{
	FAST_PRINT;

	int n;
	cin >> n;

	vector<int> fruitVec(n + 1);

	for (int i = 0; i < n; i++)
	{
		cin >> fruitVec[i];
		fruitVec[i]--;
	}

	if (n == 1)
	{
		cout << 1;
		return 0;
	}

	int curFruits[10];
	memset(curFruits, 0, sizeof(curFruits));
	int max = 0;
	int start = 0, end = 1;
	curFruits[fruitVec[0]]++;
	curFruits[fruitVec[1]]++;

	while (end < n)
	{
		if (!isFruitTypeValid(curFruits))
		{
			curFruits[fruitVec[start++]]--;
		}
		else
		{
			max = std::max(end - start + 1, max);
			curFruits[fruitVec[++end]]++;
		}
	}
	cout << max;
}
