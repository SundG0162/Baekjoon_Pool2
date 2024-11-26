#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int map[129][129];
int white = 0, blue = 0;

void findColorPaper(int x, int y, int n);
bool isColorPaper(int x, int y, int n);

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	findColorPaper(0, 0, n);

	cout << white << '\n' << blue;
}

void findColorPaper(int x, int y, int n)
{
	if (isColorPaper(x, y, n))
	{
		if (map[y][x])
		{
			blue++;
		}
		else
		{
			white++;
		}
		return;
	}
	int divided = n / 2;
	findColorPaper(x, y, divided);
	findColorPaper(x + divided, y, divided);
	findColorPaper(x, y + divided, divided);
	findColorPaper(x + divided, y + divided, divided);
}

bool isColorPaper(int x, int y, int n)
{
	int first = map[y][x];
	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (map[i][j] != first)
			{
				return false;
			}
		}
	}
	return true;
}
