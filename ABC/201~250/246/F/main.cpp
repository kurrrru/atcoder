#pragma GCC optimize ("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target ("avx512f")
#include <cstdio>
using namespace std;
using ll = long long;

ll pow_mod(ll base, ll exp, ll mod)
{
	ll ret = 1;
	while (exp)
	{
		if (exp & 1)
			ret = (ret * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return ret;
}

int main()
{
	constexpr ll mod = 998244353;
	int N, L;
	(void)scanf("%d %d", &N, &L);
	int S[18] = {};
	for (int i = 0; i < N; ++i)
	{
		char s[27];
		(void)scanf("%s", s);
		for (int j = 0; s[j]; ++j)
		{
			S[i] |= 1 << (s[j] - 'a');
		}
	}
	ll ans = 0;
	int memo[27] = {};
	for (int i = 1; i < 1 << N; ++i)
	{
		int s = ~0;
		for (int j = 0; j < N; ++j)
		{
			if ((i >> j) & 1)
				s &= S[j];
		}
		bool include = __builtin_popcount(i) & 1;
		if (include)
			memo[__builtin_popcount(s)]++;
		else
			memo[__builtin_popcount(s)]--;
	}
	for (int i = 1; i < 27; ++i)
		if (memo[i] != 0)
			ans += pow_mod(i, L, mod) * memo[i];
	ans %= mod;
	if (ans < 0)
		ans += mod;
	printf("%lld", ans);
}
