#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	constexpr ll MOD = 1'000'000'007;
	ll N, K;
	cin >> N >> K;
	vector<vector<vector<ll>>> A(60, vector<vector<ll>>(N, vector<ll>(N, 0)));
	for (ll i = 0; i < N; i++)
		for (ll j = 0; j < N; j++)
			cin >> A[0][i][j];
	for (ll k = 1; k < 60; k++)
	{
		for (ll i = 0; i < N; i++)
		{
			for (ll j = 0; j < N; j++)
			{
				for (ll l = 0; l < N; l++)
				{
					A[k][i][j] += (A[k - 1][i][l] * A[k - 1][l][j]) % MOD;
					A[k][i][j] %= MOD;
				}
			}
		}
	}
	vector<vector<ll>> dp(N, vector<ll>(N, 0));
	for (ll i = 0; i < N; i++)
		dp[i][i] = 1;
	for (ll k = 0; k < 60; k++)
	{
		if (K >> k & 1ll)
		{
			vector<vector<ll>> dp_next(N, vector<ll>(N, 0));
			for (ll i = 0; i < N; i++)
			{
				for (ll j = 0; j < N; j++)
				{
					for (ll l = 0; l < N; l++)
					{
						dp_next[i][j] += (dp[i][l] * A[k][l][j]) % MOD;
						dp_next[i][j] %= MOD;
					}
				}
			}
			dp = dp_next;
		}
	}
	ll ans = 0;
	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < N; j++)
		{
			ans += dp[i][j];
			ans %= MOD;
		}
	}
	cout << ans << endl;
}
