#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::stack;
using std::string;

queue<string>sentences[101];

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	cin.clear();

	string input = "";
	for (int i = 0; i < n; i++)
	{
		std::getline(cin, input);
		std::istringstream iss(input);

		string word;
		while (iss >> word)
		{
			sentences[i].push(word);
		}
	}

	string l;
	std::getline(cin, l);
	std::istringstream iss(l);

	string word;
	vector<string> lVector;
	while (iss >> word)
	{
		lVector.push_back(word);
	}
	for (int i = 0; i < lVector.size(); i++)
	{
		input = lVector[i];
		int failToFindCount = 0;
		for (int j = 0; j < n; j++)
		{
			if (sentences[j].empty())
			{
				failToFindCount++;
				continue;
			}
			if (sentences[j].front() == input)
			{
				sentences[j].pop();
				break;
			}
			failToFindCount++;
		}
		if (failToFindCount == n)
		{
			cout << "Impossible";
			return 0;
		}
	}

	for (int i = 0; i < n; i++) 
	{
		if (!sentences[i].empty()) 
		{
			cout << "Impossible";
			return 0;
		}
	}

	cout << "Possible";

}