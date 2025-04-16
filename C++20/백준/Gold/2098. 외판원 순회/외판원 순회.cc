#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<deque>
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
using std::priority_queue;
using std::queue;
using std::deque;
using std::stack;
using std::string;
using std::pair;
using std::unordered_map;
using std::greater;
using std::less;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

#define VERY_BIG_NUMBER 1e9

int n;
int dp[16][1 << 16];
int adj[17][17];

int tsp(int currentCity, int visited)
{
	if (visited == (1 << n) - 1) // 만약 모든 비트가 1. 즉, 모든 도시를 순회 했다면
	{
		if (adj[currentCity][0] == 0) // 0번째 도시로 돌아가야함. 근데 길이 없으니 INF 반환
			return VERY_BIG_NUMBER;
		else
			return adj[currentCity][0]; // 0번째 도시로 돌아가는 길이 있으면 그 비용 반환
	}
	if (dp[currentCity][visited] != -1) // 현재 도시에서 visited만큼 순회를 한 상태에서 0번째까지 가는 비용이 저장돼있으면 중복 계산 방지용 반환
		return dp[currentCity][visited];

	int minCost = VERY_BIG_NUMBER; // 큰 숫자

	for (int i = 0; i < n; i++) // 일단 있는 정점 모두 순회
	{
		if ((visited & (1 << i)) == 0 && adj[currentCity][i] != 0) // 방문 했는지, 길이 있는지 체킹
		{
			int toVisit = visited | (1 << i); // visited 상태 갱신
			int tempCost = tsp(i, toVisit) + adj[currentCity][i]; // 재귀 시작
			minCost = std::min(tempCost, minCost); // 모든 모든 정점에서의 최소 비용 구하기
		}
	}

	return dp[currentCity][visited] = minCost; // 반환
}


int main()
{
	FAST_PRINT;

	MEMSET(dp, -1);

	cin >> n;
	for (int i = 0, input; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> input;
			adj[i][j] = input;
		}
	}

	int result = tsp(0, 1);
	if (result == VERY_BIG_NUMBER)
		cout << 0;
	else
		cout << result;
}