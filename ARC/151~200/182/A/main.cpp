#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, Q;
	cin >> N >> Q;
	vector<ll> P(Q), V(Q);
	for (ll i = 0; i < Q; i++)
		cin >> P[i] >> V[i];
	vector<ll> A(Q, 0); // 1:+, -1:-
	for (ll i = 0; i < Q - 1; i++)
	{
		for (ll j = i + 1; j < Q; j++)
		{
			if (V[i] > V[j])
			{
				if (P[i] == P[j])
				{
					cout << 0 << endl;
					return 0;
				}
				else
				{
					if (P[i] > P[j])
					{
						if (A[i] == -1 || A[j] == 1)
						{
							cout << 0 << endl;
							return 0;
						}
						else
						{
							A[i] = 1;
							A[j] = -1;
						}
					}
					else
					{
						if (A[i] == 1 || A[j] == -1)
						{
							cout << 0 << endl;
							return 0;
						}
						else
						{
							A[i] = -1;
							A[j] = 1;
						}
					}
				}
			}
		}
	}
	ll ans = 1;
	for (ll i = 0; i < Q; i++)
	{
		if (A[i] == 0)
		{
			ans *= 2;
			ans %= 998244353;
		}
	}
	cout << ans << endl;
}
