#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<vector<pair<ll, ll>>> edge(N);
    vector<set<ll>> costlist(N);
    queue<pair<ll, ll>> que;
    for (ll i = 0; i < M; ++i) {
        ll a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        edge[a].emplace_back(b, w);
    }
    const ll max_iter = 10000000;
    que.push({0, 0});
    for (ll i = 0; i < max_iter; ++i)
    {
        if (que.empty())
            break;
        auto [u, cost] = que.front();
        que.pop();
        for (auto [v, w] : edge[u]) {
            if (costlist[v].count(cost ^ w) == 0) {
                costlist[v].insert(cost ^ w);
                que.push({v, cost ^ w});
            }
        }
    }
    if (costlist[N - 1].empty()) {
        cout << -1 << endl;
    } else {
        ll ans = *costlist[N - 1].begin();
        for (auto cost : costlist[N - 1]) {
            ans = min(ans, cost);
        }
        cout << ans << endl;
    }
}
