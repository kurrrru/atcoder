#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> W(N), H(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i] >> H[i] >> B[i];
    }
    vector<vector<ll>> dp(2, vector<ll>(500010, -1e18));
    const ll offset = 250005;
    dp[0][offset + W[0]] = B[0];
    dp[0][offset - W[0]] = H[0];
    for (int i = 1; i < N; i++) {
        // B+, H-
        for (int j = 0; j < 500010; j++) {
            dp[1][j] = -1e18;
            if (j - W[i] >= 0)
                dp[1][j] = max(dp[1][j], dp[0][j - W[i]] + B[i]);
            if (j + W[i] < 500010)
                dp[1][j] = max(dp[1][j], dp[0][j + W[i]] + H[i]);
        }
        swap(dp[0], dp[1]);
    }
    ll ans = 0;
    for (int i = offset; i < 500010; i++) {
        // if (i < offset + 10000)
            // cout << dp[N - 1][i] << " ";
        ans = max(ans, dp[0][i]);
    }
    // cout << endl;
    cout << ans << endl;

}
