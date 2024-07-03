#include<iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int area = n * m;

	bool isPossible = area % 3 == 0;

	isPossible ? cout << "YES" : cout << "NO";
}
