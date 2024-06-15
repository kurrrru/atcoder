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
	return (x);
}

int main()
{
	ll K;
	cin >> K;
	vector<ll> C(26);
	for (ll i = 0; i < 26; ++i)
		cin >> C[i];
	vector<ll> fact(1010);
	fact[0] = 1;
	for (ll i = 1; i < 1010; i++)
		fact[i] = fact[i - 1] * i % MOD;
	vector<ll> inv(1010);
	inv[1009] = inv_mod(fact[1009], MOD);
	for (ll i = 1008; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % MOD;
	auto comb = [&](ll n, ll r) -> ll
	{
		if (n < r)
			return 0;
		if (n < 0 || r < 0)
			return 0;
		return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
	};
	
	vector<vector<ll> > dp(27, vector<ll>(K + 1, 0));
	dp[0][0] = 1;
	for (ll i = 0; i < 26; i++)
	{
		for (ll j = 0; j <= K; j++)
		{
			for (ll c = 0; c <= C[i]; c++)
			{
				if (j - c < 0)
					break;
				dp[i + 1][j] += dp[i][j - c] * comb(j, c) % MOD;
				dp[i + 1][j] %= MOD;
			}
		}
	}
	ll ans = 0;
	for (ll i = 1; i <= K; i++)
	{
		ans += dp[26][i];
		ans %= MOD;
	}
	cout << ans << endl;
}
