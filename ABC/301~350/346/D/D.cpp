#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	string S;
	cin >> N >> S;
	vector<ll> C(N);
	for (ll i = 0; i < N; i++)
		cin >> C[i];
	ll dp[N + 1][2][2];
	ll INF = 1e18;
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				dp[i][j][k] = INF;
			}
		}
	}
	dp[0][0][0] = 0;
	dp[0][0][1] = 0;

	for (int i = 0; i < N; i++)
	{
		if (S[i] == '0')
		{
			dp[i + 1][0][0] = dp[i][0][1];
			dp[i + 1][0][1] = dp[i][0][0] + C[i];
			if (i >= 1)
			{
				dp[i + 1][1][0] = min(dp[i][1][1], dp[i][0][0]);
				dp[i + 1][1][1] = min(dp[i][1][0], dp[i][0][1]) + C[i];
			}
		}
		else
		{
			dp[i + 1][0][0] = dp[i][0][1] + C[i];
			dp[i + 1][0][1] = dp[i][0][0];
			if (i >= 1)
			{
				dp[i + 1][1][0] = min(dp[i][1][1], dp[i][0][0]) + C[i];
				dp[i + 1][1][1] = min(dp[i][1][0], dp[i][0][1]);
			}
		}
	}
	cout << min(dp[N][1][0], dp[N][1][1]) << endl;
}