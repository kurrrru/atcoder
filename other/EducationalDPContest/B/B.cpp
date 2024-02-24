#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	int h[N];
	for (int i = 0; i < N; i++)
		cin >> h[i];
	int dp[N];
	dp[0] = 0;
	for (int i = 1; i < N; i++)
	{
		int tmp = 2e9;
		for (int j = max(0, i - K); j < i; j++)
			tmp = min(tmp, dp[j] + abs(h[j] - h[i]));
		dp[i] = tmp;
	}
	cout << dp[N - 1] << endl; 
}