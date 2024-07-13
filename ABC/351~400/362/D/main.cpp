#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1LL << 60;

vector<vector<pair<ll,ll>>> cost; // cost[u][v] u->vのコスト(辺で結ばれていなければINF)
vector<ll> d;
vector<bool> used;
ll N;

vector<ll> A;


void dijkstra(ll s) {
	d.assign(N,INF);
	used.assign(N,false);
    d[s]=A[s];
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> que;
	que.push({0,s});
    while (!que.empty())
	{
		ll v=que.top().second;
		ll _c=que.top().first;
		que.pop();
		if (d[v]<_c) continue;
		for (auto [u,c] : cost[v])
		{
			if (d[u]>d[v]+c + A[u])
			{
				d[u]=d[v] +c + A[u];
				que.push({d[u],u});
			}
		}
	}
}

signed main()
{
	ll M;
	cin >> N >> M;
	A.resize(N);
	for (ll i = 0; i < N; ++i)
		cin >> A[i];
	vector<ll> U(M), V(M), B(M);
	for (ll i = 0; i < M; ++i)
	{
		cin >> U[i] >> V[i] >> B[i];
		--U[i];
		--V[i];
	}
	cost.resize(N);
	for (ll i = 0; i < M; ++i)
	{
		cost[U[i]].push_back({V[i],B[i]});
		cost[V[i]].push_back({U[i],B[i]});
	}
	// print cost
	// for (ll i = 0; i < N; ++i)
	// {
	// 	cout << i << ": ";
	// 	for (auto [u,c] : cost[i])
	// 		cout << u << " " << c << " ";
	// 	cout << endl;
	// }
	dijkstra(0);
	for (ll i = 1; i < N; ++i)
		cout << d[i] << " \n"[i == N - 1];
}
