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
	int aa, oa;
	int ab, ob;
	cin >> aa >> oa >> ab >> ob;
	if (aa + ob > ab + oa)
	{
		cout << ab + oa;
	}
	else
		cout << aa + ob;
}