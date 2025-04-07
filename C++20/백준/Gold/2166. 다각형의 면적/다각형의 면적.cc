#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<map>
#include<unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::stack;
using std::string;

int main()
{
	int n;
	cin >> n;

	vector<std::pair<double, double>> pointVec;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		pointVec.push_back({ x,y });
	}
	pointVec.push_back(pointVec.front());

	double area = 0;
	for (int i = 0; i < n; i++)
	{
		area += pointVec[i].first * pointVec[i + 1].second - pointVec[i + 1].first * pointVec[i].second;
	}

	cout.precision(1);
	cout << std::fixed;
	cout << std::abs(area / 2);
}