#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
	ll N, M;
	cin >> N >> M;
	vector<vector<pair<ll, ll>>> cost(N);
	vector<map<ll, ll>> cost2(N);
	vector<tuple<ll, ll, ll>> edge;
	vector<string> ans(M, "?");
	for (ll i = 0; i < M; i++)
	{
		ll A, B, C;
		cin >> A >> B >> C;
		A--;
		B--;
		edge.push_back({A, B, C});
		if (cost2[A].count(B) == 0 || cost2[A][B] > C)
		{
			cost2[A][B] = C;
			cost2[B][A] = C;
			cost[A].push_back({B, C});
			cost[B].push_back({A, C});
		}
	}
	auto dist_1 = toolbox::graph::dijkstra(0, cost);
	auto dist_n = toolbox::graph::dijkstra(N - 1, cost);
	ll d = dist_n[0];
	for (ll i = 0; i < M; i++)
	{
		auto [A, B, C] = edge[i];
		if (dist_1[A] + C + dist_n[B] == d || dist_1[B] + C + dist_n[A] == d)
		{
			ans[i] = "Yes";
		}
		else
		{
			ans[i] = "No";
		}
	}
	for (auto s : ans)
	{
		if (s == "?")
			return (1);
		cout << s << endl;
	}
}
