#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, M;
	cin >> N >> M;
	vector<ll> A(N);
	for (ll i = 0; i < N; i++)
		cin >> A[i];
	vector<ll> B(N);
	for (ll i = 0; i < N; i++)
		cin >> B[i];
	vector<vector<ll>> dp(N, vector<ll>(2, 0));
	dp[0][0] = (B[0] + M - A[0]) % M;
	dp[0][1] = (A[0] + M - B[0]) % M;
	for (ll i = 1; i < N; i++)
	{
		
	}
	cout << min(dp[N - 1][0], dp[N - 1][1]) << endl;
}
