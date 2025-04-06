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

int n;
int map[11][11];

int current = 0;
int max = 0;

bool rt[21], rb[21];

void tracking(int x, int y);
void nextTracking(int x, int y);
void marking(int x, int y);
void unmarking(int x, int y);

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			map[i][j] = !map[i][j];
		}
	}

	int answer = 0;
	tracking(0, 0);
	answer += max;
	max = 0;
	tracking(1, 0);
	answer += max;

	cout << answer;
}

void tracking(int x, int y) // 트래킹 메인 함수
{
	if (map[y][x] == 1 || rt[x + y] || rb[x - y + 10])
	{
		nextTracking(x, y);
		return;
	}

	// 비숍을 놓는 경우
	marking(x, y);
	current++;
	nextTracking(x, y);
	current--;
	unmarking(x, y);

	// 비숍을 안 놓는 경우
	nextTracking(x, y);
}

void nextTracking(int x, int y) // 다음 칸의 트래킹 추적
{
	int nextX = x + 2 >= n ? !((x + 2) % 2) : x + 2;
	int nextY = x + 2 >= n ? y + 1 : y;
	if (nextY == n)
	{
		max = std::max(current, max);
		return;
	}
	tracking(nextX, nextY);
}

void marking(int x, int y) // 비숍의 위치를 기반으로 갈 수 없는 곳을 마킹하는 함수
{
	rt[x + y] = true;
	rb[x - y + 10] = true;
}

void unmarking(int x, int y) // 비숍이 위치에서 사라졌다고 가정하고 해놓은 마킹을 해제하는 함수
{
	rt[x + y] = false;
	rb[x - y + 10] = false;
}