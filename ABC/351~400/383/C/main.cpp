#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll H, W, D;
	cin >> H >> W >> D;
	vector<string> S(H);
	for (ll i = 0; i < H; i++)
		cin >> S[i];
	vector<vector<ll>> dp(H, vector<ll>(W, 1e9));
	vector<vector<ll>> humid;
	queue<pair<ll, ll>> q;
	for (ll i = 0; i < H; i++)
	{
		for (ll j = 0; j < W; j++)
		{
			if (S[i][j] == 'H')
			{
				humid.push_back({i, j});
				dp[i][j] = 0;
				q.push({i, j});
			}
		}
	}
	while (!q.empty())
	{
		auto [i, j] = q.front();
		q.pop();
		if (i > 0 && dp[i - 1][j] > dp[i][j] + 1 && S[i - 1][j] != '#')
		{
			dp[i - 1][j] = dp[i][j] + 1;
			q.push({i - 1, j});
		}
		if (i < H - 1 && dp[i + 1][j] > dp[i][j] + 1 && S[i + 1][j] != '#')
		{
			dp[i + 1][j] = dp[i][j] + 1;
			q.push({i + 1, j});
		}
		if (j > 0 && dp[i][j - 1] > dp[i][j] + 1 && S[i][j - 1] != '#')
		{
			dp[i][j - 1] = dp[i][j] + 1;
			q.push({i, j - 1});
		}
		if (j < W - 1 && dp[i][j + 1] > dp[i][j] + 1 && S[i][j + 1] != '#')
		{
			dp[i][j + 1] = dp[i][j] + 1;
			q.push({i, j + 1});
		}
	}
	ll ans = 0;
	for (ll i = 0; i < H; i++)
	{
		for (ll j = 0; j < W; j++)
		{
			if (dp[i][j] <= D)
				ans += 1;
		}
	}
	cout << ans << endl;
}
