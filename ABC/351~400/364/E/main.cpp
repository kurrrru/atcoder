#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, X, Y;
	cin >> N >> X >> Y;
	vector<pair<ll, ll>> taste(N);
	for (ll i = 0; i < N; i++)
		cin >> taste[i].first >> taste[i].second;
	sort(taste.begin(), taste.end(), [](pair<ll, ll> a, pair<ll, ll> b) { return a.second < b.second; });
	vector<vector<ll>> dp(N + 1, vector<ll>(X + 2, 100000));
	dp[0][0] = 0;
	for (ll i = 0; i < N; i++)
	{
		for (ll j = i; j >= 0; j--)
		{
			for (ll k = X; k >= 0; k--)
			{
				if (dp[j][k] <= Y)
					dp[j + 1][min(X + 1, k + taste[i].first)] = min(dp[j + 1][min(X + 1, k + taste[i].first)], min(Y + 1, dp[j][k] + taste[i].second));
			}
		}
	}
	ll ans = 0;
	for (ll i = 0; i <= N; i++)
	{
		for (ll j = 0; j <= X + 1; j++)
		{
			if (dp[i][j] <= Y + 1)
				ans = i;
		}
	}
	cout << ans << endl;
}
