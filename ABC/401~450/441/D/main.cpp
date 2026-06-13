#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M, L, S, T;
    cin >> N >> M >> L >> S >> T;
    vector<vector<pair<ll,ll>>> edge(N);
    for (int i = 0; i < M; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--;v--;
        edge[u].push_back({v,c});
    }

    vector<pair<ll,ll>> que;
    que.push_back({0,0});
    while (L-- && !que.empty()) {
        vector<pair<ll,ll>> new_que;
        for (ll i = 0 ; i < que.size() ;i++) {
            auto [u, cost] = que[i];
            for (ll j = 0; j < edge[u].size();j++) {
                new_que.push_back({edge[u][j].first, cost + edge[u][j].second});
            }
        }
        que.swap(new_que);
    }
    set<ll> s;
    for (ll i = 0; i < que.size(); i++) {
        auto [u, cost] = que[i];
        if (S <= cost && cost <= T) {
            s.insert(u);
        }
    }
    for (auto s_ : s) {
        cout << s_ + 1 << " ";
    }
    cout << endl;

}
