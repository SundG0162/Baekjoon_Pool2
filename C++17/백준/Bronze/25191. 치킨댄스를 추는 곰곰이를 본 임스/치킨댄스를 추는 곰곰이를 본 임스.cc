#include <iostream>

using namespace std;

int main()
{
	int cola;
	int beer;
	int chicken;

	cin >> chicken >> cola >> beer;

	int cnt = 0;

	while (chicken--)
	{
		if (cola >= 2)
		{
			cola -= 2;
			cnt++;
			continue;
		}
		else if (beer > 0)
		{
			beer--;
			cnt++;
			continue;
		}
		else
		{
			break;
		}
	}

	cout << cnt;
}