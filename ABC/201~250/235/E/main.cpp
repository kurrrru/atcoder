#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind {
	std::vector<int> p;
	std::vector<int> r;
	UnionFind(int n) {
		p.resize(n, -1);
		r.resize(n, 1);
	}

	int find(int x) {
		if (p[x] == -1)
			return (x);
		else
			return (p[x] = find(p[x]));
	}

	bool unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)
			return (false);
		if (r[x] > r[y])
			std::swap(x, y);
		if (r[x] == r[y])
			r[y]++;
		p[x] = y;
		return (true);
	}

	bool same(int x, int y) {
		return (find(x) == find(y));
	}
};

int main()
{
	ll N, M, Q;
	cin >> N >> M >> Q;
	UnionFind uf(N);
	vector<tuple<ll, ll, ll, ll>> edge(M + Q);
	for (ll i = 0; i < M; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		edge[i] = make_tuple(c, a - 1, b - 1, -1);
	}
	for (ll i = 0; i < Q; i++)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		edge[M + i] = make_tuple(w, u - 1, v - 1, i);
	}
	sort(edge.begin(), edge.end());
	vector<ll> ans(Q);
	for (ll i = 0; i < M + Q; i++)
	{
		ll a, b, c, d;
		tie(c, a, b, d) = edge[i];
		if (d == -1)
		{
			uf.unite(a, b);
		}
		else
		{
			ans[d] = !uf.same(a, b);
		}
	}
	for (ll i = 0; i < Q; i++)
	{
		if (ans[i])
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
}
