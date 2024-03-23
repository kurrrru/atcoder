#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S="wbwbwwbwbwbw";
	for (int i = 0; i < 100; i++)
	{
		S+="wbwbwwbwbwbw";
	}
	int W, B;
	cin >> W >> B;
	bool flag = false;
	for (int i = 0; i < S.size(); i++)
	{
		for (int j = i; j < S.size(); j++)
		{
			int cnt[2] = {0, 0};
			for (int k = i; k <= j; k++)
			{
				if (S[k] == 'w')
					cnt[0]++;
				else
					cnt[1]++;
			}
			if (cnt[0] == W && cnt[1] == B)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}