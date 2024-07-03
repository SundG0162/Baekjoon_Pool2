#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin >> m;
	string command;
	vector<int> vec;
	int param;
	for (int i = 0; i < m; i++)
	{
		cin >> command;
		if (command == "add")
		{
			cin >> param;
			if (find(vec.begin(), vec.end(), param) == vec.end())
				vec.push_back(param);
		}
		else if (command == "remove")
		{
			cin >> param;
			auto it = find(vec.begin(), vec.end(), param);
			if (it != vec.end())
				vec.erase(it);
		}
		else if (command == "check")
		{
			cin >> param;
			if (find(vec.begin(), vec.end(), param) == vec.end())
				cout << 0 << '\n';
			else
				cout << 1 << '\n';
		}
		else if (command == "toggle")
		{
			cin >> param;
			auto it = find(vec.begin(), vec.end(), param);
			if (it == vec.end())
				vec.push_back(param);
			else
				vec.erase(it);
		}
		else if (command == "all")
		{
			vec.clear();
			for (int j = 1; j <= 20; j++)
				vec.push_back(j);
		}
		else if (command == "empty")
		{
			vec.clear();
		}
	}
}