#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> edge(N);
    for (int i = 0; i < M; i++) {
        ll x, y;
        cin >> x >> y;
        x--;y--;
        edge[y].push_back(x);
    }
    vector<ll> first_black(N, 1e9);
    ll q;
    cin >> q;
    vector<pair<ll,ll>> query;
    vector<pair<ll,ll>> idxs;
    for (ll i = 0; i < q; i++) {
        ll op, v;
        cin >> op >> v;
        v--;
        if (op == 1) {
            if (first_black[v] < i) continue;
            first_black[v] = i;
            idxs.push_back({i, v});
        }
        else {
            query.push_back({i, v});
        }
    }

    for (int i = 0; i < idxs.size(); i++) {
        if (first_black[idxs[i].second] < idxs[i].first) {
            continue;
        }
        stack<ll> s;
        s.push(idxs[i].second);
        while (!s.empty()) {
            ll u = s.top();s.pop();
            for (int j = 0; j < edge[u].size(); j++) {
                if (first_black[edge[u][j]] > first_black[u]) {
                    s.push(edge[u][j]);
                    first_black[edge[u][j]] = first_black[u];
                }
            }
        }
        
    }

    for (int i = 0; i < query.size(); i++) {
        if (query[i].first > first_black[query[i].second]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

}
