#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<ll> S(N);
	set<ll> T;
	for (ll i = 0; i < N; i++)
	{
		cin >> S[i];
		// T[S[i] - 1] = 1;
		T.insert(S[i] - 1);
	}
	ll ans = 0;
	for (ll i = 1; i < 1000000 - 1; i++)
	{
		if (T.count(i) == 0)
			continue;
		auto i_it = T.find(i);
		if (i < 1000000 - 1 / 2)
		{
			for (auto it = T.begin(); it != i_it; it++)
			{
				if (T.count(2 * i - *it) == 1)
				{
					ans++;
				}
			}
		}
		else
		{
			for (auto it = i_it; it != T.end(); it++)
			{
				if (T.count(2 * *it - i) == 1)
				{
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}
