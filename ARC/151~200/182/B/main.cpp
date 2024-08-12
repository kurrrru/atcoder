#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll T;
	cin >> T;
	while (T--)
	{
		ll N, K;
		cin >> N >> K;
		for (ll i = 0; i < N; i++)
		{
			if (i >= (1 << (K - 1)))
				cout << 1 << " \n"[i == N - 1];
			else
			{
				ll x = 1 << (K - 1);
				for (ll j = 0; j < K - 1; j++)
				{
					if ((i >> j) & 1)
						x |= 1 << (K - 2 - j);
				}
				cout << x << " \n"[i == N - 1];
			}
		}
	}

}
