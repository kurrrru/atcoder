#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;

int main()
{
	string K;
	ll D;
	cin >> K >> D;
	ll N = K.size();
	vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(N, vector<ll>(D, 0)));
	for (ll i = 0; i < K[0] - '0'; i++)
		dp[0][0][i % D]++;
	dp[1][0][(K[0] - '0') % D]++;
	for (ll i = 1; i < N; i++)
	{
		for (ll j = 0; j < D; j++)
		{
			for (ll k = 0; k < 10; k++)
			{
				dp[0][i][(j + k) % D] += dp[0][i - 1][j];
				dp[0][i][(j + k) % D] %= MOD;
			}
			for (ll k = 0; k < K[i] - '0'; k++)
			{
				dp[0][i][(j + k) % D] += dp[1][i - 1][j];
				dp[0][i][(j + k) % D] %= MOD;
			}
			dp[1][i][(j + K[i] - '0') % D] += dp[1][i - 1][j];
			dp[1][i][(j + K[i] - '0') % D] %= MOD;
		}
	}
	cout << (dp[0][N - 1][0] + dp[1][N - 1][0] - 1 + MOD) % MOD << endl;
}
