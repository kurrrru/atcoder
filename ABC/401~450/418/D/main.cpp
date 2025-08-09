#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<vector<ll>> dp(N + 1, vector<ll>(2, 0));
    ll ans = 0;
    for (ll i = 0; i < N; ++i) {
        if (S[i] == '0') {
            dp[i + 1][0] += dp[i][1] + 1;
            dp[i + 1][1] += dp[i][0];
        } else {
            dp[i + 1][0] += dp[i][0];
            dp[i + 1][1] += dp[i][1] + 1;
        }
        ans += dp[i + 1][1];
        // cout << dp[i + 1][0] << " " << dp[i + 1][1] << endl;
    }
    cout << ans << endl;
}