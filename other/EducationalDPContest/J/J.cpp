#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double dfs(double c0, double c1, double c2, double c3, vector<vector<vector<double>>> &dp)
{
	if (c1 < 0 || c2 < 0 || c3 < 0)
		return 0;
	if (dp[c1][c2][c3] > 0)
		return dp[c1][c2][c3];
	ll total = c1 + c2 + c3;
	dp[c1][c2][c3] = dfs(c0 + 1, c1 - 1, c2, c3, dp) * c1 / total + dfs(c0, c1 + 1, c2 - 1, c3, dp) * c2 / total + dfs(c0, c1, c2 + 1, c3 - 1, dp) * c3 / total + c0 / total + 1;
	return dp[c1][c2][c3];
}

int main()
{
	ll N;
	cin >> N;
	vector<ll> C(4, 0);
	for (ll i = 0; i < N; i++)
	{
		ll A;
		cin >> A;
		C[A]++;
	}
	vector<vector<vector<double>>> dp(N + 1, vector<vector<double>>(N + 1, vector<double>(N + 1, 0)));
	dp[1][0][0] = N;
	cout << fixed << setprecision(10) << dfs(C[0], C[1], C[2], C[3], dp) << endl;
}
