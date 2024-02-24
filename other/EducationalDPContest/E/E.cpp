#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int N, W, V = 100000;
	cin >> N >> W;
	vector<vector<ll> > dp(N + 1, vector<ll>(V + 1, W + 1));
	dp[0][0] = 0;
	for (int i = 0; i < N; i++)
	{
		int w, v;
		cin >> w >> v;
		for (int j = 0; j <= V; j++)
		{
			dp[i + 1][j] = dp[i][j];
			if (j >= v && dp[i + 1][j] > dp[i][j - v] + w)
				dp[i + 1][j] = dp[i][j - v] + w;
		}
	}
	int ans = 0;
	for (int i = V; i >= 0; i--)
	{
		if (dp[N][i] <= W)
		{
			ans = i;
			break ;
		}
	}
	cout << ans << endl;
}
