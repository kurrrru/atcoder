#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct unionfind
{
	std::vector<int> p;
	std::vector<int> r;
	unionfind(int n)
	{
		p.resize(n, -1);
		r.resize(n, 1);
	}

	int find(int x)
	{
		if (p[x] == -1)
			return (x);
		else
			return (p[x] = find(p[x]));
	}

	bool unite(int x, int y)
	{
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

	bool same(int x, int y)
	{
		return (find(x) == find(y));
	}
};

int main()
{
	ll N, M;
	cin >> N >> M;
	ll A, B;
	unionfind uf(N);
	vector<tuple<ll, ll, ll>> v;
	for (ll i = 0; i < M; i++)
	{
		cin >> A >> B;
		A--;
		B--;
		if (!uf.unite(A, B))
		{
			v.push_back(make_tuple(A, B, i));
		}
	}
	ll groups = 0;
	for (ll i = 0; i < N; i++)
	{
		if (uf.p[i] < 0)
			groups++;
	}
	cout << groups - 1 << endl;
	if (groups == 1)
		return (0);
	ll cnt = 0;
	for (ll i = 0; i < N; i++)
	{
		if (uf.p[i] != -1)
			continue;
		for (ll j = cnt; j < v.size(); j++)
		{
			if (uf.same(i, get<0>(v[j])) || uf.same(i, get<1>(v[j])))
				continue;
			cout << get<2>(v[j]) + 1 << " " << get<0>(v[j]) + 1 << " " << i + 1 << endl;
			uf.p[i] = get<1>(v[j]);
			swap(v[j], v[cnt]);
			cnt++;
			break;
		}
		if (cnt == groups - 1)
			break;
	}
}
