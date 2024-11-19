#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, M;
	cin >> N >> M;
	vector<vector<pair<ll, ll>>> in(N), out(N);
	for (ll i = 0; i < M; i++)
	{
		ll a, b, w;
		cin >> a >> b >> w;
		a--;
		b--;
		in[b].push_back({ a, w });
		out[a].push_back({ b, w });
	}
	vector<ll> ans(N, 0);
	vector<bool> visited(N, false);
	queue<ll> q;
	for (ll i = 0; i < N; i++)
	{
		if (visited[i])
		{
			continue;
		}
		q.push(i);
		visited[i] = true;
		while (!q.empty())
		{
			ll v = q.front();
			q.pop();
			for (auto [u, w] : out[v])
			{
				if (visited[u])
				{
					continue;
				}
				ans[u] = ans[v] + w;
				visited[u] = true;
				q.push(u);
			}
			for (auto [u, w] : in[v])
			{
				if (visited[u])
				{
					continue;
				}
				ans[u] = ans[v] - w;
				visited[u] = true;
				q.push(u);
			}
		}
	}
	for (ll i = 0; i < N; i++)
	{
		cout << ans[i] << " \n"[i + 1 == N];
	}
}
