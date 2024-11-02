#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<math.h>

using namespace std;

const int R = 31;
const int M = 1234567891;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int l;
	cin >> l;
	string str;
	cin >> str;
	int hash = 0;
	for (int i = 0; i < str.size(); i++)
	{
		hash += (str[i] - 'a' + 1) * pow(R, i);
	}

	cout << hash;
}