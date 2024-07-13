#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 998244353;

int main()
{
	ll N, M;
	cin >> N >> M;
	ll ans = 0;
	for (int i = 60; i >= 0; i--)
	{
		if ((M >> i) & 1L)
			ans += ((N & ~((1L << (i + 1L)) - 1L)) >> 1L);
		if ((M >> i) & 1L && (N >> i) & 1L)
			ans += N - (N & ~((1L << i) - 1L)) + 1L;
		ans %= mod;
	}
	cout << ans << endl;
}
