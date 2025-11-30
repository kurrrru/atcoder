#include <bits/stdc++.h>
using namespace std;
using ll=long long;

bool reachable(const vector<string> &grid, ll H, ll W) {
    // std::cout << "CALLED" << endl;
    // for (ll i = 0 ; i < H; i++) {
    //     cout << grid[i] << endl;
    // }
    bool ans = true;
    vector<pair<ll,ll>> bs;
    for (ll i = 0; i < H; i++) {
        for (ll j = 0;j < W; j++) {
            if (grid[i][j] == 'B') {
                bs.push_back({i,j});
                break;
            }
        }
    }
    std::vector<pair<ll,ll>> adjs;
    adjs.push_back({1,0});
    adjs.push_back({-1,0});
    adjs.push_back({0,1});
    adjs.push_back({0,-1});

    for (ll bsi = 0; bsi < 4; bsi++) {
        ll x = bs[0].first, y = bs[0].second, nx = x + adjs[bsi].first, ny = y + adjs[bsi].second;
        if (nx < 0 || ny < 0 || nx >= H || ny >= W || grid[nx][ny] != '.') continue;
        stack<pair<ll,ll>> que;
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        que.push({nx,ny});
        visited[x][y] = true;
        visited[nx][ny] = true;
        // cout << "B found" << endl;
        ll cnt = 0;
        while (!que.empty()) {
            // cout << "size: " << que.size() << ", top: " << que.top().first << "," << que.top().second << endl;
            auto [i,j] = que.top();que.pop();
            for (ll k = 0; k < 4; k++) {
                ll ni = i + adjs[k].first;
                ll nj = j + adjs[k].second;
                if (ni < 0 || nj < 0 || ni >= H || nj >= W) {
                    continue;
                }
                // cout << ni << "," << nj << endl;

                if (visited[ni][nj]) continue;
                // cout << ni << "," << nj << endl;
                visited[ni][nj] = true;
                if (grid[ni][nj] == 'B') {
                    cnt++;
                } else if (grid[ni][nj] == '.') {
                    que.push({ni,nj});
                }
            }
            // cout << que.size() << endl;
        }
        if (cnt == 2)
            return true;
    }
    // {
    //     stack<pair<ll,ll>> que;
    //     vector<vector<bool>> visited(H, vector<bool>(W, false));
    //     for (ll i = H - 1; i >= 0; i--) {
    //         for (ll j = W - 1; j >= 0; j--) {
    //             if (grid[i][j] == 'B') {
    //                 que.push(make_pair(i,j));
    //                 visited[i][j] = true;
    //                 break;
    //             }
    //         }
    //         if (!que.empty()) {
    //             break;
    //         }
    //     }
    //     ll cnt = 0;
    //     while (!que.empty()) {
    //         auto [i,j] = que.top();que.pop();
    //         std::vector<pair<ll,ll>> adjs;
    //         adjs.push_back({1,0});
    //         adjs.push_back({-1,0});
    //         adjs.push_back({0,1});
    //         adjs.push_back({0,-1});
    //         for (ll k = 0; k < 4; k++) {
    //             ll ni = i + adjs[k].first;
    //             ll nj = j + adjs[k].second;
    //             if (ni < 0 || nj < 0 || ni >= H || nj >= W) {
    //                 continue;
    //             }
    //             if (visited[ni][nj]) continue;
    //             visited[ni][nj] = true;
    //             if (grid[ni][nj] == 'B') {
    //                 cnt++;
    //             } else if (grid[ni][nj] == '.') {
    //                 que.push({ni,nj});
    //             }
    //         }
    //     }
    //     ans &= (cnt == 2);
    // }
    return false;  // true
}

int main () {
    ll H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for (ll i = 0; i < H; i++) {
        cin >> grid[i];
    }
    ll cnt = 0;
    for (ll m1 = 0; m1 < H * W; m1++) {
        ll x1 = m1 / W;
        ll y1 = m1 % W;
        if (grid[x1][y1] != '.') continue;
        for (ll m2 = m1 + 1; m2 < H * W; m2++) {
            ll x2 = m2 / W;
            ll y2 = m2 % W;
            if (m1 == m2 || grid[x2][y2] != '.') continue;
            for (ll m3 = m2 +1; m3 < H * W; m3++) {
                ll x3 = m3 / W;
                ll y3 = m3 % W;
                if (m1 == m3 || m2 == m3 || grid[x3][y3] != '.') continue;
                vector<string> tmp = grid;
                tmp[x1][y1] = 'B'; 
                tmp[x2][y2] = 'B'; 
                tmp[x3][y3] = 'B'; 
                if (reachable(tmp,H, W)) {
                    cnt ++;
                }
            }  
        }
    }
    cout << cnt << endl;
}