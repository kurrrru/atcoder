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
	vector<ll> acc(N + 1, 0);
	for (ll i = 0; i < N; i++)
		acc[i + 1] = acc[i] + A[i];
	vector<vector<ll>> dp(N, vector<ll>(N, 1LL << 60));
	for (ll i = 0; i < N; i++)
		dp[i][i] = 0;
	for (ll k = 1; k < N; k++)
	{
		for (ll i = 0; i < N - k; i++)
		{
			ll j = i + k;
			for (ll l = i; l < j; l++)
				dp[i][j] = min(dp[i][j], dp[i][l] + dp[l + 1][j] + acc[j + 1] - acc[i]);
		}
	}
	cout << dp[0][N - 1] << endl;
}
