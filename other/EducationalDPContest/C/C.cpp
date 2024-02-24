#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int dp[N + 1][3] = {};
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dp[i + 1][0] = max(dp[i][1], dp[i][2]) + a;
		dp[i + 1][1] = max(dp[i][0], dp[i][2]) + b;
		dp[i + 1][2] = max(dp[i][0], dp[i][1]) + c;
	}
	cout << max(dp[N][0], max(dp[N][1], dp[N][2])) << endl;
}