#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    for (ll i = 0; i < 16; ++i) {
        ll A = (i >> 3) & 1;
        ll B = (i >> 2) & 1;
        ll C = (i >> 1) & 1;
        ll D = (i >> 0) & 1;
        vector<vector<ll>> dp(N + 1, vector<ll>(2, 0));
        vector<vector<ll>> length(N + 1, vector<ll>(2, 0));
        ll ans = 0, max_length = -1;
        for (ll i = 0; i < N; ++i) {
            if (S[i] == '0') {
                dp[i + 1][0] += 1;
                dp[i + 1][C] += dp[i][1];
                dp[i + 1][A] += dp[i][0];
                length[i + 1][0] = 1;
                if (dp[i][1] > 0) {
                    length[i + 1][C] = max(length[i + 1][C], length[i][1] + 1);
                }
                if (dp[i][0] > 0) {
                    length[i + 1][A] = max(length[i + 1][A], length[i][0] + 1);
                }
            } else {
                dp[i + 1][1] += 1;
                dp[i + 1][B] += dp[i][0];
                dp[i + 1][D] += dp[i][1];
                length[i + 1][1] = 1;
                if (dp[i][0] > 0) {
                    length[i + 1][B] = max(length[i + 1][B], length[i][0] + 1);
                }
                if (dp[i][1] > 0) {
                    length[i + 1][D] = max(length[i + 1][D], length[i][1] + 1);
                }
            }
            ans += dp[i + 1][1];
            if (length[i + 1][1] > 0) {
                max_length = max(max_length, length[i + 1][1]);
            }
            // cout << dp[i + 1][0] << " " << dp[i + 1][1] << endl;
        }
        cout << max_length << " " << ans << endl;
    }
}
/*
1010
1011

0 ... 4
00 ... 3
000 ... 2
0000 ... 1


*/