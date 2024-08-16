#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll H, W;
	cin >> H >> W;
	vector<vector<ll>> A(H, vector<ll>(W));
	for (ll i = 0; i < H; i++)
	{
		for (ll j = 0; j < W; j++)
		{
			cin >> A[i][j];
		}
	}
	constexpr ll INF = 1ll << 60;
	vector<vector<vector<ll>>> dp(H, vector<vector<ll>>(2, vector<ll>(2, INF)));
	dp[0][0][0] = 0;
	dp[0][0][1] = 1;
	dp[0][1][0] = 0;
	dp[0][1][1] = 1;
	for (ll i = 1; i < H; i++)
	{
		ll cnt_isolated_ff = 0;
		ll cnt_isolated_fb = 0;
		ll cnt_isolated_bf = 0;
		ll cnt_isolated_bb = 0;
		for (ll l = 0; l < W; l++)
		{
			if ((l != 0 && A[i - 1][l - 1] == A[i - 1][l]) || (l != W - 1 && A[i - 1][l] == A[i - 1][l + 1]))
			{
				continue;
			}
			if ((i - 1 == 0 || A[i - 2][l] != A[i - 1][l]) && (A[i - 1][l] != A[i][l]))
			{
				cnt_isolated_ff++;
			}
			if ((i - 1 == 0 || A[i - 2][l] != A[i - 1][l]) && (A[i - 1][l] == A[i][l]))
			{
				cnt_isolated_fb++;
			}
			if ((i - 1 == 0 || A[i - 2][l] == A[i - 1][l]) && (A[i - 1][l] != A[i][l]))
			{
				cnt_isolated_bf++;
			}
			if ((i - 1 == 0 || A[i - 2][l] == A[i - 1][l]) && (A[i - 1][l] == A[i][l]))
			{
				cnt_isolated_bb++;
			}
		}
		if (cnt_isolated_ff == 0)
		{
			dp[i][0][0] = min(dp[i][0][0], dp[i - 1][0][0]);
			dp[i][1][1] = min(dp[i][1][1], dp[i - 1][1][1] + 1);
		}
		if (cnt_isolated_bf == 0)
		{
			dp[i][0][0] = min(dp[i][0][0], dp[i - 1][1][0]);
			dp[i][1][1] = min(dp[i][1][1], dp[i - 1][0][1] + 1);
		}
		if (cnt_isolated_fb == 0)
		{
			dp[i][0][1] = min(dp[i][0][1], dp[i - 1][0][0] + 1);
			dp[i][1][0] = min(dp[i][1][0], dp[i - 1][1][1]);
		}
		if (cnt_isolated_bb == 0)
		{
			dp[i][0][1] = min(dp[i][0][1], dp[i - 1][1][0] + 1);
			dp[i][1][0] = min(dp[i][1][0], dp[i - 1][0][1]);
		}
		if (dp[i][0][0] == INF && dp[i][0][1] == INF && dp[i][1][0] == INF && dp[i][1][1] == INF)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	ll ans = INF;
	ll cnt_isolated_ff = 0;
	ll cnt_isolated_fb = 0;
	for (ll i = 0; i < W; i++)
	{
		if ((i != 0 && A[H - 1][i - 1] == A[H - 1][i]) || (i != W - 1 && A[H - 1][i] == A[H - 1][i + 1]))
		{
			continue;
		}
		if (A[H - 2][i] != A[H - 1][i])
		{
			cnt_isolated_ff++;
		}
		if (A[H - 2][i] == A[H - 1][i])
		{
			cnt_isolated_fb++;
		}
	}
	if (cnt_isolated_ff == 0)
		ans = min(ans, min(dp[H - 1][0][0], dp[H - 1][1][1]));
	if (cnt_isolated_fb == 0)
		ans = min(ans, min(dp[H - 1][0][1], dp[H - 1][1][0]));
	if (ans == INF)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << ans << endl;
	}
}
