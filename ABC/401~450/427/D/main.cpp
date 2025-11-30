#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 1 alice, -1 bob
// int dfs(std::vector<std::vector<ll>> edges)

int main() {
    ll T;
    cin >> T;
    while (T--) {
        ll N, M, K;
        cin >> N >> M >> K;
        std::string S;
        cin >> S;
        std::vector<std::vector<ll>> outedge(N), inedge(N);
        while (M--) {
            ll u,v;
            cin >> u >> v;
            u--;v--;
            outedge[u].push_back(v);
            inedge[v].push_back(u);
        }
        std::vector<ll> win(N, 0);
        for (ll i = 0; i < N; i++) {
            if (S[i] == 'B')
                win[i] = -1;
            else
                win[i] = 1;
        }
        for (ll k = 0; k < K; k++) {
            std::vector<ll> newwin(N, 1);
            bool bobfound = false;
            for (ll i = 0; i < N; i++) {
                for (ll j = 0; j < outedge[i].size(); j++) {
                    ll to = outedge[i][j];
                    if (win[to] == -1) {
                        bobfound = true;
                        newwin[i] = -1;
                        break;
                    }
                }
            }
            win = newwin;
            newwin.assign(N, -1);
            bool alicefound = false;
            for (ll i = 0; i < N; i++) {
                for (ll j = 0; j < outedge[i].size(); j++) {
                    ll to = outedge[i][j];
                    if (win[to] == 1) {
                        alicefound = true;
                        newwin[i] = 1;
                        break;
                    }
                }
            }
            win = newwin;
        }
        if (win[0] == 1)
            cout << "Alice" << endl;
        else if (win[0] == -1)
            cout << "Bob" << endl;
    }
}