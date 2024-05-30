#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// // using priority_queue
// ll prim_algorithm(vector<vector<pair<ll, ll>>> &G, vector<ll> &last_edge) // (to, cost)
// {
// 	ll N = G.size();
// 	vector<bool> used(N, false);
// 	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
// 	que.push(make_pair(0, 0));
// 	ll res = 0;
// 	while (!que.empty())
// 	{
// 		auto [cost, v] = que.top();
// 		que.pop();
// 		if (used[v])
// 			continue;
// 		used[v] = true;
// 		res += cost;
// 		last_edge[v] = cost;
// 		for (auto [to, c] : G[v])
// 		{
// 			if (!used[to])
// 				que.push(make_pair(c, to));
// 		}
// 	}
// 	return (res);
// }

int main()
{
	ll N, Q;
	cin >> N >> Q;
	vector<vector<pair<ll, ll>>> G(N);
	vector<ll> max_edge(N, 0);
	ll mst = 0;
	for (ll i = 0; i < N - 1; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		G[a].push_back(make_pair(b, c));
		G[b].push_back(make_pair(a, c));
		max_edge[a] = max(max_edge[a], c);
		max_edge[b] = max(max_edge[b], c);
		mst += c;
	}
	for (ll i = 0; i < Q; i++)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		ll now_max = w;
		now_max = max(now_max, max_edge[u]);
		now_max = max(now_max, max_edge[v]);
		cout << mst - now_max << endl;
		if (max_edge[u] > w)
			max_edge[u] = w;
		if (max_edge[v] > w)
			max_edge[v] = w;
	}
	// cout << mst << endl;
	return (0);
}
