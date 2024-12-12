#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::string;

using namespace std;


int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() != s2.size())
	{
		cout << 0;
		return 0;
	}
	if (s1[0] != s2[0])
	{
		cout << 0;
		return 0;
	}

	int min = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] == s2[i])
		{
			if (s1[i] == '8')
				min++;
			else
				continue;
		}
		else
			break;
	}
	cout << min;
}
