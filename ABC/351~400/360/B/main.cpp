#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	string S, T;
	cin >> S >> T;
	for (int w = 1; w < S.size(); w++)
	{
		for (int c = 0; c < w; c++)
		{
			string tmp = "";
			for (int k = 0; k <= S.size() / w; k++)
			{
				if (k * w + c < S.size())
					tmp += S[k * w + c];
			}
			if (tmp == T)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}
