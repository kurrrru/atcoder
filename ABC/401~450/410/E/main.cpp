#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ll N, H, M;
    cin >> N >> H >> M;
    vector<ll> A(N), B(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, -1));
    dp[0][M] = H;
    for (ll i = 1; i <= N; i++) {
        for (ll m = 0; m <= M; m++) {
            if (m + B[i - 1] <= M)
                dp[i][m] = dp[i - 1][m + B[i - 1]];
            dp[i][m] = max(dp[i][m], dp[i - 1][m] - A[i - 1]);
        }
    }
    ll ans = 0;
    for (ll i = 0; i <= N; i++) {
        for (ll m = 0; m <= M; m++) {
            if (dp[i][m] >= 0) {
                ans = max(ans, i);
            }
            // cout << dp[i][m] << " \n"[m == M];
        }
        
    }
    cout << ans << endl;
}
