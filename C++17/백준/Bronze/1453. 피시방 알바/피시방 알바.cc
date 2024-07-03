#include<iostream>
#include<string>
#include<map>
#include<set>
#include<unordered_set>
#include<iostream>
using namespace std;

int main()
{
	bool arr[101]{ {false} };
	int n;
	cin >> n;

	int place, cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> place;
		if (!arr[place])
			arr[place] = true;
		else
		{
			cnt++;
		}
	}
	cout << cnt;
}
