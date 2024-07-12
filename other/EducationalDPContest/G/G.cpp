#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n, m;
	cin >> n >> m;
	vector<vector<vector<ll>>> edge(n, vector<vector<ll>>(2));
	for (ll i = 0; i < m; i++)
	{
		ll x, y;
		cin >> x >> y;
		edge[x - 1][0].push_back(y - 1); // to
		edge[y - 1][1].push_back(x - 1); // from
	}
	vector<ll> dp(n, -1);
	vector<bool> visited(n, false);
	function<ll(ll)> dfs = [&](ll u)
	{
		if (visited[u])
			return dp[u];
		visited[u] = true;
		for (ll v : edge[u][0])
		{
			dp[u] = max(dp[u], dfs(v));
		}
		dp[u]++;
		return dp[u];
	};
	for (ll i = 0; i < n; i++)
	{
		if (!visited[i])
			dfs(i);
	}
	cout << *max_element(dp.begin(), dp.end()) << endl;
}
