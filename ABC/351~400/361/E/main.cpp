#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<vector<pair<ll, ll>>> e(N);
	ll total = 0;
	for (ll i = 0; i < N - 1; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		e[a].push_back({b, c});
		e[b].push_back({a, c});
		total += c * 2;
	}
	ll u = 0;
	vector<ll> d(N, -1);
	d[0] = 0;
	queue<ll> q;
	q.push(0);
	for (ll i = 0; i < N; i++)
	{
		ll x = q.front();
		q.pop();
		for (auto [y, z] : e[x])
		{
			if (d[y] != -1)
				continue;
			d[y] = d[x] + z;
			q.push(y);
		}
		if (d[x] > d[u])
			u = x;
	}
	d.assign(N, -1);
	d[u] = 0;
	q.push(u);
	for (ll i = 0; i < N; i++)
	{
		ll x = q.front();
		q.pop();
		for (auto [y, z] : e[x])
		{
			if (d[y] != -1)
				continue;
			d[y] = d[x] + z;
			q.push(y);
		}
		if (d[x] > d[u])
			u = x;
	}
	cout << total - d[u] << endl;
}
