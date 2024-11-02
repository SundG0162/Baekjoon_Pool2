#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<math.h>

using namespace std;

const int R = 31;
const int M = 1234567891;

long long int pow_m(int x, int y, int m)
{
	long long int v = 1;
	for (int i = 0; i < y; i++)
	{
		v = (v * x) % m;
	}
	return v % m;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int l;
	cin >> l;
	string str;
	cin >> str;
	long long int hash = 0;
	for (int i = 0; i < str.size(); i++)
	{
		hash += ((str[i] - 'a' + 1) * pow_m(R, i, M));
	}

	cout << hash % M;
}