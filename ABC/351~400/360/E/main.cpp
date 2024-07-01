#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

long long	extgcd(long long a, long long b, long long& x, long long& y) {
	long long	d;

	d = a;
	if (b != 0)
	{
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else
	{
		x = 1;
		y = 0;
	}
	return (d);
}

long long	inv_mod(long long base, long long mod)
{
	long long	x;
	long long	y;

	extgcd(base, mod, x, y);
	return ((x + mod) % mod);
}

int main()
{
	// p = p * (1 - (2 N - 2) / N^2) + (1-p) * (2 / N^2) 
	ll N, K;
	cin >> N >> K;
	vector<ll> dp(K + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= K; i++)
	{
		dp[i] = dp[i - 1] * (1 - ((2 * N - 2) * inv_mod(N * N, MOD)) % MOD + MOD) % MOD;
		dp[i] += (1 - dp[i - 1] + MOD) * (2 * inv_mod(N * N, MOD)) % MOD;
		dp[i] %= MOD;
	}
	ll ans = dp[K] + (((1 - dp[K] + MOD) * ((N * (N + 1) / 2) % MOD - 1 + MOD)) % MOD) * inv_mod(N - 1, MOD) % MOD;
	ans %= MOD;
	cout << ans << endl;
}
