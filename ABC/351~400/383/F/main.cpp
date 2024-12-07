#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, X, K;
	cin >> N >> X >> K;
	vector<ll> P(N), U(N), C(N);
	vector<vector<ll>> color(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> P[i] >> U[i] >> C[i];
		color[C[i] - 1].push_back(i);
	}
	vector<ll> order;
	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < color[i].size(); j++)
		{
			order.push_back(color[i][j]);
		}
	}
	vector<vector<ll>> dp(N + 1, vector<ll>(X + 1, -1));
	dp[0][0] = 0;
	for (ll i = 0; i < N; i++)
	{
		for (ll k = 0; k <= X; k++)
		{
			dp[i + 1][k] = max(dp[i + 1][k], dp[i][k]);
		}
		for (ll j = 0; j < color[i].size(); j++)
		{
			for (ll k = X; k >= 0; k--)
			{
				if (dp[i][k] != -1)
				{
					if (k + P[color[i][j]] <= X)
					{
						dp[i + 1][k + P[color[i][j]]] = max(dp[i + 1][k + P[color[i][j]]], dp[i][k] + U[color[i][j]] + K);
					}
				}
				if (dp[i + 1][k] != -1)
				{
					if (k + P[color[i][j]] <= X)
					{
						dp[i + 1][k + P[color[i][j]]] = max(dp[i + 1][k + P[color[i][j]]], dp[i + 1][k] + U[color[i][j]]);
					}
				}
			}
		}
	}
	// dump
	// for (ll i = 0; i <= N; i++)
	// {
	// 	for (ll j = 0; j <= X; j++)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	ll ans = 0;
	for (ll i = 0; i <= X; i++)
	{
		ans = max(ans, dp[N][i]);
	}
	cout << ans << endl;
}
