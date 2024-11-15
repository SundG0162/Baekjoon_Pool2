#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int n;
bool finded = false;
string map[9];
int row[9], col[9], box[9];

void tracking(int x, int y);
void nextTracking(int x, int y);
vector<int> findPossibleNumbers(int x, int y);
void place(int x, int y, int n);
void undo(int x, int y);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 9; i++)
	{
		cin >> map[i];
	}

	tracking(0, 0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
}


void nextTracking(int x, int y)
{
	int nextY = x + 1 == 9 ? y + 1 : y;
	int nextX = x + 1 == 9 ? 0 : x + 1;
	if (nextY == 9)
	{
		finded = true;
		return;
	}
	tracking(nextX, nextY);
}

void tracking(int x, int y) {
	if (finded) return;
	if (map[y][x] != '0') {
		nextTracking(x, y);
		return;
	}

	vector<int> possible = findPossibleNumbers(x, y);
	for (int n : possible) 
	{
		place(x, y, n);
		nextTracking(x, y);
		if (finded) return;
		undo(x, y);
	}
}

vector<int> findPossibleNumbers(int x, int y) {
	bool numbers[9] = { false };
	vector<int> possible;
	for (int i = 0; i < 9; i++)
		if (map[i][x] != '0')
			numbers[map[i][x] - '1'] = true;
	for (int i = 0; i < 9; i++)
		if (map[y][i] != '0')
			numbers[map[y][i] - '1'] = true;
	int startX = x / 3 * 3;
	int startY = y / 3 * 3;
	for (int i = startY; i < startY + 3; i++)
	{
		for (int j = startX; j < startX + 3; j++)
		{
			if (map[i][j] != '0')
				numbers[map[i][j] - '1'] = true;
		}
	}
	for (int i = 0; i < 9; i++) {
		if (!numbers[i]) {
			possible.push_back(i + 1);
		}
	}
	return possible;
}

void place(int x, int y, int n)
{
	map[y][x] = n + '0';
}

void undo(int x, int y)
{
	map[y][x] = '0';
}