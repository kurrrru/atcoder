#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int N, W;
	cin >> N >> W;
	ll dp[N + 1][W + 1] = {};
	for (int i = 0; i < N; i++)
	{
		int w, v;
		cin >> w >> v;
		for (int j = 0 ; j <= W; j++)
		{
			dp[i + 1][j] = dp[i][j];
			if (j >= w && dp[i + 1][j] < dp[i][j - w] + v)
				dp[i + 1][j] = dp[i][j - w] + v;
		}
	}
	ll ans = 0;
	for (int i = 0; i <= W; i++)
		ans = max(ans, dp[N][i]);
	cout << ans << endl;
}