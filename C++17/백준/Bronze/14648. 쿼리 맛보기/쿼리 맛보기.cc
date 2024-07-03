#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, q;
	cin >> n >> q;

	vector<long long> seqVec;

	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		seqVec.push_back(input);
	}

	int a, b, c, d;
	long long sum = 0;
	for (int i = 0; i < q; i++)
	{
		cin >> input;
		switch (input)
		{
			case 1 :
			{
				cin >> a >> b;

				for (int j = a - 1; j < b; j++)
				{
					sum += seqVec[j];
				}

				swap(seqVec[a - 1], seqVec[b - 1]);

				break;
			}
			case 2 :
			{
				cin >> a >> b >> c >> d;

				for (int j = a - 1; j < b; j++)
				{
					sum += seqVec[j];
				}

				for (int j = c - 1; j < d; j++)
				{
					sum -= seqVec[j];
				}

				break;
			}
		}

		cout << sum << '\n';

		sum = 0;
	}
}
