#include <bits/stdc++.h>
using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

void solve(vector<string>& answer, int left, int top, int size)
{
	if (size == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == 1 && j == 1)
					answer[top + i][left + j] = ' ';
				else
					answer[top + i][left + j] = '*';
			}
		}
		return;
	}

	int divided = size / 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			solve(answer, left + divided * j, top + divided * i, divided);
		}
	}
	for (int i = 0; i < divided; i++)
	{
		for (int j = 0; j < divided; j++)
		{
			answer[top + i + divided][left + j + divided] = ' ';
		}
	}

}

int main()
{
	FAST_PRINT;

	int n;
	cin >> n;

	vector<string> answer(n);
	for (int i = 0; i < answer.size(); i++)
		answer[i].resize(n);

	solve(answer, 0, 0, n);

	for (int i = 0; i < n; i++)
	{
		cout << answer[i] << '\n';
	}

	return 0;
}