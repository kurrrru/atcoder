#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1'000'000'007;

ll dfs(ll u, vector<vector<ll>> &adjs, vector<vector<ll>> &dp)
{
	dp[u][0] = 1;
	dp[u][1] = 1;
	for (ll v : adjs[u])
	{
		if (dp[v][0] > 0)
			continue;
		dfs(v, adjs, dp);
		dp[u][0] = dp[u][0] * ((dp[v][0] + dp[v][1]) % MOD) % MOD;
		dp[u][1] = dp[u][1] * dp[v][0] % MOD;
	}
	return (dp[u][0] + dp[u][1]) % MOD;
}

int main()
{
	ll N;
	cin >> N;
	vector<vector<ll>> adjs(N);
	for (ll i = 0; i < N - 1; i++)
	{
		ll x, y;
		cin >> x >> y;
		adjs[x - 1].push_back(y - 1);
		adjs[y - 1].push_back(x - 1);
	}
	vector<vector<ll>> dp(N, vector<ll>(2, 0));
	cout << dfs(0, adjs, dp) << endl;
}
