#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll R, B, x, y;
	cin >> R >> B >> x >> y;
	ll l = 0, r = min(R / x, B);
	while (r - l > 2)
	{
		ll m1 = l + (r - l) / 3;
		ll m2 = r - (r - l) / 3;
		ll a1 = m1, b1 = min(R - m1 * x, (B - m1) / y);
		ll a2 = m2, b2 = min(R - m2 * x, (B - m2) / y);
		if (a1 + b1 < a2 + b2)
			l = m1;
		else
			r = m2;
	}
	ll ans = 0;
	for (ll i = l; i <= r; i++)
	{
		ll a = i, b = min(R - i * x, (B - i) / y);
		ans = max(ans, a + b);
	}
	cout << ans << endl;
}
