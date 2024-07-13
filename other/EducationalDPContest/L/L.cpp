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
	vector<vector<ll>> dp(N, vector<ll>(N, 0));
	for (ll i = 0; i < N; i++)
		dp[i][i] = A[i];
	for (ll k = 1; k < N; k++)
	{
		for (ll i = 0; i < N - k; i++)
		{
			ll j = i + k;
			dp[i][j] = max(A[i] - dp[i + 1][j], A[j] - dp[i][j - 1]);
		}
	}
	cout << dp[0][N - 1] << endl;
}
