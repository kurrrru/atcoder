#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, M;
	cin >> N >> M;
	vector<vector<vector<ll>>> X(N, vector<vector<ll>>(N));
	for (ll i = 0; i < M; i++)
	{
		ll l, r, x;
		cin >> l >> r >> x;
		X[l - 1][r - 1].push_back(x - 1);
	}
	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < N; j++)
		{
			sort(X[i][j].begin(), X[i][j].end());
			auto it = unique(X[i][j].begin(), X[i][j].end());
			X[i][j].erase(it, X[i][j].end());
		}
	}
	vector<vector<vector<ll>>> order(N, vector<vector<ll>>(N));
	for (ll i = 0; i < N; i++)
	{
		if (X[i][i].size() == 1)
		{
			cout << 0 << endl;
			return 0;
		}
		order[i][i].push_back(1);
	}
	for (ll i = 0; i < N - 1; i++)
	{
		ll j = i + 1;
		if (X[i][j].size() == 2)
		{
			cout << 0 << endl;
			return 0;
		}
		else if (X[i][j].size() == 1 && X[i][j][0] == i)
		{
			order[i][j] = { 3, 1 };
		}
		else if (X[i][j].size() == 1 && X[i][j][0] == j)
		{
			order[i][j] = { 1, 3 };
		}
		else
		{
			order[i][j] = { 1, 1 };
		}
	}
	for (ll width = 3; width <= N; width++)
	{
		for (ll i = 0; i <= N - width; i++)
		{
			ll j = i + width - 1;
			vector<ll> order_ij = order[i][j - 1];
			vector<ll> &tmp = order[i + 1][j];
			order_ij.push_back(tmp[width - 2]);
			for (ll k = 1; k < width - 1; k++)
			{
				order_ij[k] = max(order_ij[k], tmp[k - 1]);
			}
			// ll right_end = tmp[width - 2];
			// ll same_idx = -1;
			// ll prev_idx = -1;
			// ll left_end = order[i][j - 1][0];
			// ll same_idx2 = -1;
			// for (ll k = 0; k < width - 2; k++)
			// {
			// 	if (tmp[k] == right_end)
			// 	{
			// 		same_idx = k;
			// 	}
			// 	if (tmp[k] == right_end - 2)
			// 	{
			// 		prev_idx = k;
			// 	}
			// 	if (order_ij[k + 1] == left_end)
			// 	{
			// 		same_idx2 = k;
			// 	}
			// }
			// if (right_end == 1)
			// {
			// 	order_ij.push_back(1);
			// }
			// else if (same_idx != -1) // ok
			// {
			// 	order_ij.push_back(order_ij[same_idx + 1] - 1);
			// }
			// else if (prev_idx != -1 && same_idx2 != -1 && order_ij[0] == 1)
			// {
			// 	order_ij.push_back(0);
			// }
			// else if (prev_idx != -1)
			// {
			// 	order_ij.push_back(1);
			// }
			// else
			// {
			// 	order_ij.push_back(order_ij[prev_idx + 1] + 1);
			// }
			if (order_ij[width - 1] % 2 == 0)
			{
				ll tmp = order_ij[width - 1];
				for (ll k = 0; k < width - 1; k++)
				{
					if (order_ij[k] > tmp)
					{
						order_ij[k] += 2;
					}
				}
				order_ij[width - 1] = tmp + 1;
			}

			// order check
			bool two_flag = false;
			for (ll k = 0; k < X[i][j].size(); k++)
			{
				if (order_ij[X[i][j][k]] == 1)
				{
					order_ij[X[i][j][k]] = 2;
					two_flag = true;
				}
			}
			bool one_flag = false;
			for (ll k = 0; k < width; k++)
			{
				if (order_ij[k] == 1)
				{
					one_flag = true;
					break;
				}
			}
			if (!one_flag)
			{
				cout << width << endl;
			}
			if (two_flag)
			{
				for (ll k = 0; k < width; k++)
				{
					if (order_ij[k] > 2)
					{
						order_ij[k] += 2;
					}
					else if (order_ij[k] == 2)
					{
						order_ij[k] = 3;
					}
				}
			}
			swap(order[i][j], order_ij);
		}
	}
	for (ll i = 0; i < order[0][N - 1].size(); i++)
	{
		cout << order[0][N - 1][i] << " \n"[i == N - 1];
	}
	const ll MOD = 998244353;
	vector<ll> fact(N + 1);
	fact[0] = 1;
	for (ll i = 1; i <= N; i++)
	{
		fact[i] = fact[i - 1] * i % MOD;
	}
	vector<ll> ord = order[0][N - 1];
	vector<ll> cnt(N * 2 + 1);
	for (ll i = 0; i < N; i++)
	{
		cnt[ord[i]]++;
	}
	ll ans = 1;
	for (ll i = 1; i <= N * 2; i++)
	{
		ans = ans * fact[cnt[i]] % MOD;
	}
	cout << ans << endl;

}

