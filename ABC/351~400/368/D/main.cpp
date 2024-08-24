#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, K;
	cin >> N >> K;
	vector<vector<ll>> edge(N);
	for (ll i = 0; i < N - 1; ++i)
	{
		ll a, b;
		cin >> a >> b;
		--a;
		--b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	unordered_set<ll> V;
	for (ll i = 0; i < K; ++i)
	{
		ll v;
		cin >> v;
		--v;
		V.insert(v);
	}
	vector<ll> deg(N);
	queue<ll> q;
	for (ll i = 0; i < N; ++i)
	{
		deg[i] = edge[i].size();
		if (deg[i] == 1 && V.count(i) == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		ll v = q.front();
		q.pop();
		deg[v] = 0;
		for (ll u : edge[v])
		{
			if (deg[u] == 0)
				continue;
			--deg[u];
			if (deg[u] == 1 && V.count(u) == 0)
				q.push(u);
		}
	}
	ll ans = 0;
	for (ll i = 0; i < N; ++i)
		if (deg[i] >= 1)
			ans += deg[i];
	cout << ans / 2 + 1 << endl;
}
