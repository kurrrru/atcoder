#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ext_gcd(ll a, ll b, ll &x, ll &y)
{
	assert(a != 0 || b != 0);
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll d = ext_gcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

ll inv_mod(ll a, ll m)
{
	ll x, y;
	ext_gcd(a, m, x, y);
	return (m + x % m) % m;
}

struct unionfind
{
	std::vector<int> p;
	std::vector<int> r;
	std::vector<int> size;
	unionfind(int n)
	{
		p.resize(n, -1);
		r.resize(n, 1);
		size.resize(n, 1);
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
		size[y] += size[x];
		return (true);
	}

	bool same(int x, int y)
	{
		return (find(x) == find(y));
	}

	int get_size(int x)
	{
		return (size[find(x)]);
	}
};

int main()
{
	ll N, K;
	cin >> N >> K;
	vector<vector<ll>> A(N, vector<ll>(N));
	for (ll i = 0; i < N; i++)
		for (ll j = 0; j < N; j++)
			cin >> A[i][j];
	unionfind uf_row_swap(N), uf_col_swap(N), uf_row_id(N), uf_col_id(N);
	for (ll i = 0; i < N; i++)
	{
		for (ll j = i + 1; j < N; j++)
		{
			bool ok_swap = true, ok_id = true;
			for (ll k = 0; k < N; k++)
			{
				if (A[i][k] + A[j][k] > K)
					ok_swap = false;
				if (A[i][k] != A[j][k])
					ok_id = false;
			}
			if (ok_swap)
				uf_row_swap.unite(i, j);
			if (ok_id)
				uf_row_id.unite(i, j);
			ok_swap = true;
			ok_id = true;
			for (ll k = 0; k < N; k++)
			{
				if (A[k][i] + A[k][j] > K)
					ok_swap = false;
				if (A[k][i] != A[k][j])
					ok_id = false;
			}
			if (ok_swap)
				uf_col_swap.unite(i, j);
			if (ok_id)
				uf_col_id.unite(i, j);
		}
	}
	constexpr ll MOD = 998244353;
	vector<ll> fact(N + 1), inv(N + 1);
	fact[0] = 1;
	for (ll i = 1; i <= N; i++)
		fact[i] = fact[i - 1] * i % MOD;
	inv[N] = inv_mod(fact[N], MOD);
	for (ll i = N - 1; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % MOD;
	ll ans = 1;
	vector<bool> done(N, false);
	for (ll i = 0; i < N; i++)
	{
		if (done[uf_row_swap.find(i)])
			continue;
		done[uf_row_swap.find(i)] = true;
		ans = ans * fact[uf_row_swap.get_size(i)] % MOD;
	}
	done.assign(N, false);
	for (ll i = 0; i < N; i++)
	{
		if (done[uf_col_swap.find(i)])
			continue;
		done[uf_col_swap.find(i)] = true;
		ans = ans * fact[uf_col_swap.get_size(i)] % MOD;
	}
	done.assign(N, false);
	for (ll i = 0; i < N; i++)
	{
		if (done[uf_row_id.find(i)])
			continue;
		done[uf_row_id.find(i)] = true;
		ans = ans * inv[uf_row_id.get_size(i)] % MOD;
	}
	done.assign(N, false);
	for (ll i = 0; i < N; i++)
	{
		if (done[uf_col_id.find(i)])
			continue;
		done[uf_col_id.find(i)] = true;
		ans = ans * inv[uf_col_id.get_size(i)] % MOD;
	}
	cout << ans << endl;
}
