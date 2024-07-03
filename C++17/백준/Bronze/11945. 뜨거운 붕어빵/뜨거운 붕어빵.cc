#include<iostream>
#include<string>
#include<map>
#include<set>
#include<unordered_set>
#include<iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	string str = "";
	for (int i = 0; i < n; i++)
	{
		cin >> str;

		for (int j = m - 1; j >= 0; j--)
		{
			cout << str[j];
		}
		cout << endl;
		str = "";
	}
}
