#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
	ll H, W, M;
	cin >> H >> W >> M;
	vector<pair<ll, ll>> l(H, {-1, 0}), c(W, {-1, 0});
	for (int i = 0; i < M; i++)
	{
		ll T, A, X;
		cin >> T >> A >> X;
		if (T == 1)
			l[A - 1] = {i, X};
		else
			c[A - 1] = {i, X};
	}
	ll ans[200001] = {};
	sort(l.begin(), l.end());
	sort(c.begin(), c.end());
	for (int i = 0; i < H; i++)
	{
		ans[l[i].second] += upper_bound(c.begin(), c.end(), l[i]) - c.begin();
	}
	for (int i = 0; i < W; i++)
	{
		ans[c[i].second] += lower_bound(l.begin(), l.end(), c[i]) - l.begin();
	}
	ll cnt = 0;
	for (int i = 0; i < 200001; i++)
	{
		if (ans[i] > 0)
		{
			cnt++;
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < 200001; i++)
	{
		if (ans[i] > 0)
		{
			cout << i << " " << ans[i] << endl;
		}
	}
}
