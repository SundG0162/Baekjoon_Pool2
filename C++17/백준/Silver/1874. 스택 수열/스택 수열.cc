#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int m = 1;
	bool flag = false;
	string str = "";
	stack<int> s;

	for (int i = 0, x; i < n; i++)
	{
		cin >> x;
		if (flag) continue;
		while (true)
		{
			if (!s.empty() && s.top() == x)
			{
				s.pop();
				str += "-\n";
				break;
			}
			else if (!s.empty() && s.top() != x && x < m)
			{
				flag = true;
				str = "NO";
				break;
			}
			else
			{
				str += "+\n";
				s.push(m);
				if (x == m)
				{
					s.pop();
					str += "-\n";
					m++;
					break;
				}
				m++;
			}
		}
	}
	cout << str;
}