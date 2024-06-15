#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, M;
	cin >> N >> M;
	vector<string> S(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> S[i];
	}
	ll ans = M + 1;
	for (ll i = 0; i < (1 << N); i++)
	{
		vector<bool> ok(M, false);
		for (ll j = 0; j < N; j++)
		{
			if (i & (1 << j))
			{
				for (ll k = 0; k < M; k++)
				{
					if (S[j][k] == 'o')
					{
						ok[k] = true;
					}
				}
			}
		}
		bool flag = true;
		for (ll j = 0; j < M; j++)
		{
			if (!ok[j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			ans = min(ans, (ll)__builtin_popcount(i));
		}
	}
	cout << ans << endl;
}
