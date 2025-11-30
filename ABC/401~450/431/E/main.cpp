#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void update(vector<vector<vector<ll>>> &dp, deque<tuple<ll,ll,char>> &que, ll cost, ll i, ll j, ll diff, char dir) {
    ll H = dp.size();
    ll W = dp[0].size() - 1;
    ll flag = 0;
    if (dir == 'u') flag = 0;
    else if (dir == 'd') flag = 1;
    else if (dir == 'l') flag = 2;
    else if (dir == 'r') flag = 3;

    if (i < 0 || j < 0 || i >= H || j >= W + 1) return;
    if (cost + diff < dp[i][j][flag]) {
        if (cost + diff < dp[i][j][flag]) {
            dp[i][j][flag] = cost + diff;
        }
        if (diff == 1) { 
            que.push_front({i,j,dir});
        } else {
            que.push_back({i,j,dir});
        }
    }
}

int main() {
    ll T;
    cin >> T;
    while (T--) {
        ll H, W;
        cin >> H >> W;
        vector<string> S(H);
        for (int i = 0; i < H; i++) {
            cin >> S[i];
        }
        vector<vector<vector<ll>>> dp(H, vector<vector<ll>>(W + 1, vector<ll>(4, 1e18)));
        dp[0][0][3] = 0;
        deque<tuple<ll,ll,char>> que;
        que.push_back({0,0,'r'});
        while (!que.empty()) {
            auto [s,t,dir] = que.back(); que.pop_back();
            if (s == H - 1 && t == W && dir == 'r') {
                cout << dp[s][t][3] << endl;
                break;
            }
            if (s < 0 || t < 0 || s >= H || t >= W) continue;
            if (dir == 'r') {
                update(dp, que, dp[s][t][3], s - 1, t, S[s][t] != 'C', 'u');
                update(dp, que, dp[s][t][3], s, t + 1, S[s][t] != 'A', 'r');
                update(dp, que, dp[s][t][3], s + 1, t, S[s][t] != 'B', 'd');
            } else if (dir == 'l') {
                update(dp, que, dp[s][t][2], s - 1, t, S[s][t] != 'B', 'u');
                update(dp, que, dp[s][t][2], s, t - 1, S[s][t] != 'A', 'l');
                update(dp, que, dp[s][t][2], s + 1, t, S[s][t] != 'C', 'd');
            } else if (dir == 'u') {
                update(dp, que, dp[s][t][0], s - 1, t, S[s][t] != 'A', 'u');
                update(dp, que, dp[s][t][0], s, t - 1, S[s][t] != 'B', 'l');
                update(dp, que, dp[s][t][0], s, t + 1, S[s][t] != 'C', 'r');
            } else if (dir == 'd') {
                update(dp, que, dp[s][t][1], s, t - 1, S[s][t] != 'C', 'l');
                update(dp, que, dp[s][t][1], s, t + 1, S[s][t] != 'B', 'r');
                update(dp, que, dp[s][t][1], s + 1, t, S[s][t] != 'A', 'd');
            }
        }
        
    }
}
