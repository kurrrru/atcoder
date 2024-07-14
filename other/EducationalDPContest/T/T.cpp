// I have read the following editorial
// https://atcoder.jp/contests/dp/editorial/3722
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;

int main()
{
	ll N;
	string s;
	cin >> N >> s;
	vector<vector<ll>> dp(N, vector<ll>(N, 0));
	dp[0][0] = 1;
	for (ll i = 1; i < N; i++)
	{
		vector<ll> sum(i + 1, 0);
		for (ll j = 0; j < i; j++)
			sum[j + 1] = (sum[j] + dp[i - 1][j]) % MOD;
		for (ll j = 0; j <= i; j++)
		{
			if (s[i - 1] == '<')
			{
				dp[i][j] = sum[j];
			}
			else if (s[i - 1] == '>')
			{
				dp[i][j] = sum[i] - sum[j];
				if (dp[i][j] < 0)
					dp[i][j] += MOD;
			}
		}
	}
	ll ans = 0;
	for (ll i = 0; i < N; i++)
		ans = (ans + dp[N - 1][i]) % MOD;
	cout << ans << endl;
}
