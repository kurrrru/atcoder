#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1'000'000'007;

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
	vector<vector<int>> dp(N, vector<int>(1 << N, 0));
	for (int i = 0; i < N; i++)
	{
		if (A[0][i] == 1)
			dp[0][1 << i] = 1;
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 1 << N; j++)
		{
			if (dp[i - 1][j] == 0)
				continue;
			for (int k = 0; k < N; k++)
			{
				if (A[i][k] == 0 || j >> k & 1)
					continue;
				dp[i][j | 1 << k] = (dp[i][j | 1 << k] + dp[i - 1][j]) % MOD;
			}
		}
	}
	cout << dp[N - 1][(1 << N) - 1] << endl;
}
