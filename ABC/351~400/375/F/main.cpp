#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, M, Q;
	cin >> N >> M >> Q;
	vector<ll> A(M), B(M), C(M);
	for (ll i = 0; i < M; i++)
	{
		cin >> A[i] >> B[i] >> C[i];
		A[i]--;
		B[i]--;
	}
	vector<bool> ok(M, true);
	vector<ll> block;
	vector<vector<pair<ll, ll>>> query(310);
	ll idx = 0;
	while (Q--)
	{
		ll op;
		cin >> op;
		if (op == 1)
		{
			ll i;
			cin >> i;
			i--;
			block.push_back(i);
			ok[i] = false;
			idx++;
		}
		else
		{
			ll l, r;
			cin >> l >> r;
			l--;
			r--;
			query[idx].push_back({l, r}); // あとから後ろから走査
		}
	}
	vector<vector<ll>> dist(N, vector<ll>(N, 1e18));
	for (ll i = 0; i < N; i++)
	{
		dist[i][i] = 0;
	}
	for (ll i = 0; i < M; i++)
	{
		if (ok[i])
		{
			dist[A[i]][B[i]] = min(dist[A[i]][B[i]], C[i]);
			dist[B[i]][A[i]] = min(dist[B[i]][A[i]], C[i]);
		}
	}
	for (ll k = 0; k < N; k++)
	{
		for (ll i = 0; i < N; i++)
		{
			for (ll j = 0; j < N; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	vector<ll> ans;
	for (ll i = block.size(); i >= 0; i--)
	{
		// block[i]を戻す
		// cout << "[i, block[i], block_size] = " << i << " " << block[i] << " " << block.size() << endl;
		// cout << "[A[block[i]], B[block[i]], C[block[i]]] = " << A[block[i]] << " " << B[block[i]] << " " << C[block[i]] << endl;
		// cout << "dist[A[block[i]]][B[block[i]]] = " << dist[A[block[i]]][B[block[i]]] << endl;
		if (i < block.size() && dist[A[block[i]]][B[block[i]]] > C[block[i]])
		{
			dist[A[block[i]]][B[block[i]]] = C[block[i]];
			dist[B[block[i]]][A[block[i]]] = C[block[i]];
			for (ll j = 0; j < N; j++)
			{
				for (ll k = 0; k < N; k++)
				{
					dist[j][k] = min(dist[j][k], dist[j][A[block[i]]] + dist[A[block[i]]][B[block[i]]] + dist[B[block[i]]][k]);
					dist[j][k] = min(dist[j][k], dist[j][B[block[i]]] + dist[B[block[i]]][A[block[i]]] + dist[A[block[i]]][k]);
				}
			}
		}
		for (ll j = query[i].size() - 1; j >= 0; j--)
		{
			ll l = query[i][j].first;
			ll r = query[i][j].second;
			ans.push_back(dist[l][r] >= 1e18 ? -1 : dist[l][r]);
		}
	}
	for (ll i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i] << endl;
	}
}
