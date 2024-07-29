#include <bits/stdc++.h>
using std::cout, std::cin, std::endl, std::vector, std::pair, std::map, std::sort;
using ll = long long;

vector<ll> prev;

#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <vector>
#include <queue>

namespace toolbox
{

namespace graph
{

/**
* @brief Dijkstra's algorithm
* @tparam Vertex Type of vertex
* @tparam Cost Type of cost
* @tparam INF Cost of infinity
* @tparam Zero Cost of zero
* @param s Start vertex
* @param cost Adjacency list of graph
* @return Shortest distance from start vertex
* @note [constraint] each cost must be non-negative
* @note [complexity] O((V + E) log V)
* @note If you want to get the shortest path, you should record the previous vertex. (not implemented)
*/
template <typename Vertex, typename Cost, Cost INF, Cost Zero>
std::vector<Cost> dijkstra(const Vertex s, const std::vector<std::vector<std::pair<Vertex, Cost>>> &cost)
{
	int N = cost.size();
	std::vector<Cost> dist(N, INF);
	prev.resize(N, -1);
    dist[s] = Zero;
	std::priority_queue<std::pair<Cost, Vertex>, std::vector<std::pair<Cost, Vertex>>, std::greater<std::pair<Cost, Vertex>>> que;
	que.push({0, s});
    while (!que.empty())
	{
		auto [s_dist, s] = que.top();
		que.pop();
		if (dist[s] < s_dist)
			continue;
		for (auto [t, t_cost] : cost[s])
		{
			if (dist[t] <= dist[s] + t_cost)
				continue;
			dist[t] = dist[s] + t_cost;
			que.push({dist[t], t});
			prev[t] = s;
		}
	}
	return dist;
}

std::vector<long long> dijkstra(const long long s, const std::vector<std::vector<std::pair<long long, long long>>> &cost)
{
	return dijkstra<long long, long long, 1ll << 60, 0ll>(s, cost);
}

} // namespace graph

} // namespace toolbox

#endif

int main()
{
	const ll INF = 1LL << 60;
	int N, M;
	cin >> N >> M;
	vector<vector<pair<ll, ll>>> cost(N);
	map<pair<ll, ll>, ll> mp;
	for (int i = 0; i < M; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		cost[a].emplace_back(b, c);
		cost[b].emplace_back(a, c);
		mp[{a, b}] = i + 1;
		mp[{b, a}] = i + 1;
	}
	vector<ll> dist = toolbox::graph::dijkstra(0, cost);
	vector<ll> ans;
	for (int i = 1; i < N; i++)
	{
		ans.emplace_back(mp[{i, prev[i]}]);
	}
	for (int i = 0; i < N - 1; i++)
	{
		cout << ans[i] << " \n"[i == N - 2];
	}
}
