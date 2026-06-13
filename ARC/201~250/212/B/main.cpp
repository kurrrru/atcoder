#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;

    ll X,Y,C;
    M--;
    vector<ll> x(M), y(M), c(M);
    cin >> X>>Y>>C;
    X--;Y--;
    vector<vector<tuple<ll,ll,ll>>> edge(N);
    for (ll i = 0; i < M; i++) {
        cin >> x[i] >> y[i] >> c[i];
        x[i]--;
        y[i]--;
        edge[x[i]].push_back({y[i],c[i],i});
        // edge[y[i]].push_back({x[i],c[i],i});
    }

    vector<bool> used(M);

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    ll goal = X;
    pq.push({C,Y});

    while (!pq.empty()) {
        auto [cost_now, y_now] = pq.top(); pq.pop();
        // std::cout << cost_now << " " << y_now << endl;
        if (y_now == goal) {
        cout << cost_now << endl;
            return 0;
        }
        for (const auto ne: edge[y_now]) {
            auto cost_next = get<1>(ne);
            auto y_next = get<0>(ne);
            auto i = get<2>(ne);

            if (used[i]) continue;
            used[i] = true;
            pq.push({cost_now + cost_next, y_next});
        }
    }
    std::cout << -1 << endl;



}
