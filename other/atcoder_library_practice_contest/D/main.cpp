#include <bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
using namespace std;

int main () {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    atcoder::mf_graph<ll> g(N * M + 2);
    const ll source = 0;
    const ll sink = N * M + 1;
    // グラフ構築
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M; j++) {
            ll index = i * M + j + 1;
            if (index % 2 == 0)
                g.add_edge(source, index, 1); // source
            else
                g.add_edge(index, sink, 1); // sink
            if (S[i][j] == '#')
                continue;
            const vector<pair<ll, ll>> directions = {
                {1, 0}, {0, 1}, {-1, 0}, {0, -1}
            };
            if (index % 2 == 1)
                continue;
            for (ll k = 0; k < 4; k++) {
                ll ni = i + directions[k].first;
                ll nj = j + directions[k].second;
                if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
                    if (S[ni][nj] == '#')
                        continue;
                    ll next_index = ni * M + nj + 1;
                    if (index % 2 == 0) {
                        g.add_edge(index, next_index, 1);
                    }
                }
            }
        }
    }

    // 最大フロー計算
    ll max_flow = g.flow(source, sink);
    cout << max_flow << endl;

    // タイルを置く
    vector<string> result(S);
    for (const auto& e : g.edges()) {
        if (e.from == source || e.to == sink)
            continue;
        if (e.flow == 0)
            continue;
        ll from_index = e.from - 1;
        ll to_index = e.to - 1;
        ll from_i = from_index / M;
        ll from_j = from_index % M;
        ll to_i = to_index / M;
        ll to_j = to_index % M;
        if (from_i == to_i) {
            if (from_j < to_j) {
                result[from_i][from_j] = '>';
                result[to_i][to_j] = '<';
            } else {
                result[from_i][from_j] = '<';
                result[to_i][to_j] = '>';
            }
        } else if (from_j == to_j) {
            if (from_i < to_i) {
                result[from_i][from_j] = 'v';
                result[to_i][to_j] = '^';
            } else {
                result[from_i][from_j] = '^';
                result[to_i][to_j] = 'v';
            }
        }
    }
    for (const auto& row : result) {
        cout << row << endl;
    }
}
