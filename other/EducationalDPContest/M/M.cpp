#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	constexpr ll MOD = 1'000'000'007;
	ll N, K;
	cin >> N >> K;
	vector<ll> A(N);
	for (ll i = 0; i < N; i++)
		cin >> A[i];
	vector<vector<ll>> dp(N, vector<ll>(K + 1, 0));
	for (ll j = 0; j <= A[0]; j++)
		dp[0][j] = 1;
	for (ll i = 1; i < N; i++)
	{
		dp[i][0] = dp[i - 1][0];
		for (ll j = 1; j <= K; j++)
		{
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			if (j - A[i] - 1 >= 0)
				dp[i][j] -= dp[i - 1][j - A[i] - 1];
			if (dp[i][j] < 0)
				dp[i][j] += MOD;
			if (dp[i][j] >= MOD)
				dp[i][j] -= MOD;
		}
	}
	cout << dp[N - 1][K] << endl;
}
