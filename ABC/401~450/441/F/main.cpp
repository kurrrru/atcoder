#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> P(N), V(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i] >> V[i];
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, 0));
    for (int i = 0; i < N; i++) {
        for (ll j = 0; j <= M; j++) {
            if (j < P[i]) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - P[i]] + V[i]);
            }
        }
    }
    vector<vector<bool>> visited(N + 1, vector<bool>(M + 1, false));

    vector<bool> choose(N, false), not_choose(N, false);
    queue<pair<ll,ll>> que;
    que.push({N, M});
    while (!que.empty()) {
        auto [i,j] = que.front(); que.pop();
        if (i == 0) continue;
        if (visited[i][j])continue;
        visited[i][j] = true;
        if (dp[i][j] == dp[i - 1][j]) {
            not_choose[i - 1] = true;
            que.push({i - 1, j});
        }
        if (j >= P[i - 1] && dp[i][j] == dp[i - 1][j - P[i - 1]] + V[i - 1]) {
            choose[i - 1] = true;
            que.push({i - 1, j - P[i - 1]});
        }
    }
    for (int i = 0; i < N; i ++) {
        char c;
        if (choose[i] && !not_choose[i]) {
            c = 'A';
        } else if (!choose[i] && not_choose[i]) {
            c = 'C';
        } else {
            c = 'B';
        }
        cout << c;
    }
    cout << endl;

}
