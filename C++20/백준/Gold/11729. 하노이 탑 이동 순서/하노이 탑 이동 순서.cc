#include <bits/stdc++.h>
using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

void move(int from, int to)
{
	cout << from << ' ' << to << '\n';
}

void hanoi(int n, int from, int by, int to)
{
	if (n == 0) return;
	hanoi(n - 1, from, to, by);
	move(from, to);
	hanoi(n - 1, by, from, to);
}

int main()
{
	FAST_PRINT;

	int n;
	cin >> n;
	cout << (int)pow(2, n) - 1 << '\n';
	hanoi(n, 1, 2, 3);
}