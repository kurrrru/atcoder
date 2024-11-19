#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	double ans = 0;
	ll x = 0, y = 0;
	while (N--)
	{
		ll s, t;
		cin >> s >> t;
		ans += sqrt((s - x) * (s - x) + (t - y) * (t - y));
		x = s;
		y = t;
	}
	ans += sqrt(x * x + y * y);
	cout << fixed << setprecision(10) << ans << endl;
}
