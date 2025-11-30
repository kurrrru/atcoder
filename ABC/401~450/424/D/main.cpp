#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    ll T;
    cin >> T;
    while (T--) {
        ll H, W;
        cin >> H >> W;
        vector<string> S(H);
        for (ll i = 0; i < H; i++)
            cin >> S[i];
        vector<vector<vector<ll>>> dp(H, vector<vector<ll>>(W, vector<ll>(2, 0)));
        for (ll j = 0; j < W; j++) {
            if (S[0][j] == '#')
                dp[0][j][0] = 1;
        }
        for (int i = 0; i < H; i++) {
            if (S[i][0] == '#')
                dp[i][0][1] = 1;
        }
        for (ll i = 1; i < H - 1; i++) {
            for (ll j = 1; j < W - 1; j++) {
                
            }
        }
    }
}
