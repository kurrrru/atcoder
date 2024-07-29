#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	const ll INF = 1LL << 60;
	int N, M;
	cin >> N >> M;
	vector<vector<ll>> cost(N, vector<ll>(N, INF));
	for (int i = 0; i < M; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		cost[a][b] = c;
		cost[b][a] = c;
	}
	vector<vector<ll>> dist = cost;
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	ll cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (cost[i][j] == INF)
			{
				continue;
			}
			bool ok = false;
			for (int k = 0; k < N; k++)
			{
				if (cost[i][j] >= dist[i][k] + dist[k][j])
				{
					ok = true;
					break;
				}
			}
			if (ok)
			{
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}
