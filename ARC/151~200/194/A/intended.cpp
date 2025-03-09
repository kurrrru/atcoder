#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<ll> A(N);
	for (ll i = 0; i < N; i++)
		cin >> A[i];
	vector<vector<ll>> dp(N + 2, vector<ll>(2, 0));
	for (ll i = 0; i < N; i++)
	{
		dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + A[i]);
		dp[i + 1][1] = max(dp[i + 1][1], dp[i][0]);
		if (i >= 1)
		{
			dp[i + 1][0] = max(dp[i + 1][0], dp[i - 1][1] + A[i]);
			dp[i + 1][1] = max(dp[i + 1][1], dp[i - 1][1]);
		}
	}
	dp[N + 1][0] = max(dp[N][0], dp[N - 1][1]); // N + 1を使われていることにすることで、Nを使う場合と使わない場合を考慮する
	dp[N + 1][1] = max(dp[N][1], dp[N - 1][0]);
	cout << dp[N + 1][0] << endl;
}
