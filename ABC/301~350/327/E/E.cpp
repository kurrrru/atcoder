#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int P[N];
	for (int i = 0; i < N; i++)
		cin >> P[i];
	vector<vector<double> > dp(N + 1, vector<double>(N + 1, -1e18));
	dp[0][0] = 0;
	for (int i = 1; i < N + 1; i++)
	{
		dp[i][0] = 0;
		for (int j = 1; j < i + 1; j++)
		{
			dp[i][j] = max(dp[i - 1][j], 0.9 * dp[i - 1][j - 1] + P[i - 1]);
		}
	}
	vector<double> r(N + 1, -1e18);
	double ans = -1e18;
	for (int i = 1; i < N + 1; i++)
	{
		r[i] = dp[N][i] / (10 * (1 - pow(0.9, i))) - 1200 / sqrt(i);
		ans = max(ans, r[i]);
	}
	cout << fixed << setprecision(10) << ans << endl;
}