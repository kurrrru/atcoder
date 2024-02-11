#include <bits/stdc++.h>
using namespace std;

#define inf LLONG_MAX

int main()
{
	int N;
	cin >> N;
	vector<long long> dp(N + 1, inf), A(N), B(N), X(N);
	dp[0] = 0;
	for (int i=0; i < N-1; i++)
	{
		cin >> A[i] >> B[i] >> X[i];
		X[i] -= 1;
	}
	queue<int> stack;
	stack.push(0);
	int u, updated;
	while (!stack.empty())
	{
		u = stack.front(), stack.pop();
		if (u == N - 1)
			continue;
		updated = 0;
		if (dp[u + 1] > dp[u] + A[u])
		{
			updated = 1;
			dp[u + 1] = dp[u] + A[u];
		}
		if (dp[X[u]] > dp[u] + B[u])
		{
			updated = 1;
			dp[X[u]] = dp[u] + B[u];
		}
		if (updated && dp[u + 1] < dp[X[u]])
		{
			stack.push(u + 1);
			stack.push(X[u]);
		}
		else if (updated)
		{
			stack.push(X[u]);
			stack.push(u + 1);
		}

	}

	// for (int i=1; i < N; i++)
	// {
	// 	cin >> A >> B >> X;
	// 	dp[i + 1] = min(dp[i+1],dp[i] + A);
	// 	dp[X] = min(dp[X], dp[i] + B);
	// }
	// for (int i=1; i<=N; i++)
	// {
	// 	cout << i<< " " <<dp[i] << endl;
	// }
	cout << dp[N - 1] << endl;
}