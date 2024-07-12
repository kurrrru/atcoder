#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<double> p(N), q(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> p[i];
		q[i] = log(1 - p[i]);
		p[i] = log(p[i]);
	}
	vector<vector<double>> dp(N + 1, vector<double>(N + 1, -INFINITY));
	dp[0][0] = 0;
	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < N; j++)
		{
			dp[i + 1][j + 1] = log(exp(dp[i + 1][j + 1]) + exp(dp[i][j] + p[i]));
			dp[i + 1][j] = log(exp(dp[i + 1][j]) + exp(dp[i][j] + q[i]));
		}
	}
	double ans = 0;
	for (ll i = N / 2 + 1; i <= N; i++)
		ans += exp(dp[N][i]);
	cout << fixed << setprecision(10) << ans << endl;
}
