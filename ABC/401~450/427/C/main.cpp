#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    std::vector<ll> u(M), v(M);
    ll edge[10][10] = {};
    for (int i = 0; i < M; i++) {
        cin >> u[i] >> v[i];
        edge[u[i] - 1][v[i] - 1]++;
        edge[v[i] - 1][u[i] - 1]++;
    }
    // for (ll i = 0; i < N; i++) {
    //     for (ll j = 0; j < N; j++) {
    //         std::cout << edge[i][j] << " \n"[j == N - 1];
    //     }
    // }
    ll ans = 1111111;
    for (int i = 0; i < (1 << N); i++) {
        ll cnt = 0;
        for (int j = 0; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                ll a = (i >> j) & 1;
                ll b = (i >> k) & 1;
                if (a != b) continue;
                cnt += edge[j][k];
            }
        }
        ans = min(ans, cnt);
    }
    std::cout << ans << std::endl;
}