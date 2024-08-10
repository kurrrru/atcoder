#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, K;
	cin >> N >> K;
	vector<pair<ll, ll>> A(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end(), [](pair<ll, ll> a, pair<ll, ll> b)
	{
		return a.second * b.first + b.second > a.first * b.second + a.second;
	});
	vector<vector<ll>> dp(N + 1, vector<ll>(K + 1, 1));
	for (ll i = 1; i <= N; i++)
	{
		for (ll j = 1; j <= min(i, K); j++)
		{
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] * A[i - 1].first + A[i - 1].second);
		}
	}
	cout << dp[N][K] << endl;
	// for (ll i = 0; i < N; i++)
	// 	cout << A[i].first << " " << A[i].second << endl;
	// for (ll i = 0; i <= N; i++)
	// {
	// 	for (ll j = 0; j <= K; j++)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
}
