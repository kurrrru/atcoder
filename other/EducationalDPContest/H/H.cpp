#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	const ll MOD = 1e9 + 7;
	ll H, W;
	cin >> H >> W;
	vector<string> s(H);
	for (ll i = 0; i < H; i++)
		cin >> s[i];
	vector<vector<ll>> dp(H, vector<ll>(W, 0));
	for (ll i = 0; i < H; i++)
	{
		for (ll j = 0; j < W; j++)
		{
			if (s[i][j] == '#')
				continue;
			if (i == 0 && j == 0)
				dp[i][j] = 1;
			else
			{
				if (i > 0)
					dp[i][j] += dp[i - 1][j];
				if (j > 0)
					dp[i][j] += dp[i][j - 1];
				dp[i][j] %= MOD;
			}
		}
	}
	cout << dp[H - 1][W - 1] % MOD << endl;
}
