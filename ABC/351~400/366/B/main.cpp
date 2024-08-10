#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<string> S(N), T;
	for (ll i = 0; i < N; i++)
	{
		cin >> S[i];
	}
	for (ll i = 0; i < 100; i++)
	{
		bool flag = false;
		for (ll j = 0; j < N; j++)
		{
			if (S[j].size() > i)
			{
				flag = true;
				break;
			}
		}
		if (!flag)
			break;
		string s;
		ll last = -1;
		for (ll j = 0; j < N; j++)
		{
			if (S[j].size() <= i)
			{
				s = '*' + s;
			}
			else
			{
				s = S[j][i] + s;
				if (last == -1)
					last = j;
			}
		}
		s = s.substr(0, N - last);
		T.push_back(s);
	}
	for (ll i = 0; i < T.size(); i++)
	{
		cout << T[i] << endl;
	}
}
