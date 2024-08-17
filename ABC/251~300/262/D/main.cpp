#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<ll> A(N);
	for (ll i = 0; i < N; i++)
		cin >> A[i];
	ll ans = 0;
	for (ll i = 1; i <= N; i++)
	{
		vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(i + 1, vector<ll>(i, 0)));
		dp[0][0][0] = 1;
		for (ll j = 0; j < N; j++)
		{
			for (ll k = 0; k <= i; k++)
			{
				for (ll l = 0; l < i; l++)
				{
					dp[j + 1][k][l] += dp[j][k][l];
					dp[j + 1][k][l] %= 998244353;
					if (k < i)
					{
						dp[j + 1][k + 1][(l + A[j]) % i] += dp[j][k][l];
						dp[j + 1][k + 1][(l + A[j]) % i] %= 998244353;
					}
				}
			}
		}
		ans += dp[N][i][0];
		ans %= 998244353;
	}
	cout << ans << endl;
}
