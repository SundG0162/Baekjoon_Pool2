#include <bits/stdc++.h>
using namespace std;

#define FAST_PRINT std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define BEGIN_TO_END(vec) vec.begin(), vec.end()
#define MEMSET(arr, i) memset(arr, i, sizeof(arr))

void cantor(int start, int end, string& str)
{
	if (end - start < 3)
		return;
	int third = (end - start) / 3;
	int midStart = start + third;
	int midEnd = start + 2 * third;
	string empty;
	empty.reserve(midStart);
	for (int i = midStart; i < midEnd; i++)
		str[i] = ' ';
	cantor(start, midStart, str);
	cantor(midEnd, end, str);
}

int main()
{
	FAST_PRINT;
	int n;
	while (cin >> n)
	{
		int m = pow(3, n);
		string str(m, '-');

		cantor(0, m, str);
		cout << str << '\n';
	}
	return 0;
}