#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int value;
	string str;
	for (int i = 0; i < 3; i++)
	{
		cin >> str;
		if (isdigit(str[0]))
		{
			value = stoi(str);
			value += 4 - (i + 1);
		}
	}
	if (value % 3 != 0 && value % 5 != 0)
		cout << value;
	if (value % 3 == 0)
		cout << "Fizz";
	if (value % 5 == 0)
		cout << "Buzz";
}