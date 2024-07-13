#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using S = ll;
S op(S a, S b)
{
	return max(a, b);
}
S e()
{
	return 0;
}

int main()
{
	ll N;
	cin >> N;
	vector<ll> h(N), a(N);
	for (ll i = 0; i < N; i++)
		cin >> h[i];
	for (ll i = 0; i < N; i++)
		cin >> a[i];
	atcoder::segtree<ll, op, e> dp(vector<ll>(N + 1, 0));
	for (ll i = 0; i < N; i++)
	{
		ll x = dp.prod(0, h[i]) + a[i];
		dp.set(h[i], max(dp.get(h[i]), x));
	}
	cout << dp.all_prod() << endl;
}
