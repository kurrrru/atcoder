#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    constexpr ll INF = 1e18;
    ll H, W, K;
    cin >> H >> W >> K;
    vector<vector<ll>> A(H, vector<ll>(W, INF));
    queue<pair<ll, ll>> que;
    for (ll i = 0; i < K; i++) {
        ll r, c;
        cin >> r >> c;
        r--, c--;
        A[r][c] = 0;
        que.push({r, c});
    }


    while (!que.empty()) {
        auto [r, c] = que.front();
        que.pop();
        vector<pair<ll, ll>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto [dr, dc] : directions) {
            ll nr = r + dr, nc = c + dc;
            if (nr < 0 || nr >= H || nc < 0 || nc >= W)
                continue;
            if (A[nr][nc] != INF)
                continue;

            // if (nr == 8 && nc == 6) {
            //     cout << "A[" << nr << "][" << nc << "] = " << A[nr][nc] << endl;
            //     for (ll i = 0; i < H; i++) {
            //         for (ll j = 0; j < W; j++) {
            //             if (A[i][j] == INF) {
            //                 cout << setw(3) << -1 << " \n"[j == W - 1];
            //             } else {
            //                 cout << setw(3) << A[i][j] << " \n"[j == W - 1];
            //             }
            //         }
            //     }
            //     cout << endl;
            // }
            vector<ll> cnt_adjs;
            for (auto [dr2, dc2] : directions) {
                ll nnr = nr + dr2, nnc = nc + dc2;
                if (nnr < 0 || nnr >= H || nnc < 0 || nnc >= W) {
                    cnt_adjs.push_back(INF);
                    continue;
                }
                cnt_adjs.push_back(A[nnr][nnc]);
            }
            sort(cnt_adjs.begin(), cnt_adjs.end());
            if (cnt_adjs[1] != INF && cnt_adjs[1] == A[r][c]) {
                A[nr][nc] = cnt_adjs[1] + 1;
                que.push({nr, nc});
            }

            // if (nr == 8 && nc == 6) {
            //     cout << "A[" << nr << "][" << nc << "] = " << A[nr][nc] << endl;
            //     for (ll i = 0; i < H; i++) {
            //         for (ll j = 0; j < W; j++) {
            //             if (A[i][j] == INF) {
            //                 cout << setw(3) << -1 << " \n"[j == W - 1];
            //             } else {
            //                 cout << setw(3) << A[i][j] << " \n"[j == W - 1];
            //             }
            //         }
            //     }
            //     cout << endl;
            // }


        }
    }
    ll sum = 0;
    for (ll i = 0; i < H; i++) {
        for (ll j = 0; j < W; j++) {
            if (A[i][j] == INF) {
                continue;
            }
            sum += A[i][j];
        }
    }

    // for (ll i = 0; i < H; i++) {
    //     for (ll j = 0; j < W; j++) {
    //         if (A[i][j] == INF) {
    //             cout << setw(3) << -1 << " \n"[j == W - 1];
    //         } else {
    //             cout << setw(3) << A[i][j] << " \n"[j == W - 1];
    //         }
    //     }
    // }


    cout << sum << endl;
}
