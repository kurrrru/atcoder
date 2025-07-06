#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll H, W, K;
    cin >> H >> W >> K;
    ll sx = 0, sy = 0, gx = H - 1, gy = W - 1;
    vector<pair<ll, ll>> points(K);
    set<ll> xs, ys;
    xs.insert(sx);
    ys.insert(sy);
    xs.insert(gx);
    ys.insert(gy);
    for (ll i = 0; i < K; i++) {
        ll r, c;
        cin >> r >> c;
        r--, c--;
        points[i] = {r, c};
        xs.insert(r);
        ys.insert(c);
        if (r + 1 < H) {
            xs.insert(r + 1);
        }
        if (c + 1 < W) {
            ys.insert(c + 1);
        }
        if (r - 1 >= 0) {
            xs.insert(r - 1);
        }
        if (c - 1 >= 0) {
            ys.insert(c - 1);
        }
    }
    map<ll, ll> x_map, y_map;
    ll x_idx = 0, y_idx = 0;
    for (auto x : xs) {
        x_map[x] = x_idx++;
    }
    for (auto y : ys) {
        y_map[y] = y_idx++;
    }
    const ll INF = 1ll<<60;
    const ll obj = (1ll<<60) + 1;
    vector<vector<ll>> A(x_idx, vector<ll>(y_idx, INF));
    for (ll i = 0; i < K; i++) {
        ll r = points[i].first, c = points[i].second;
        A[x_map[r]][y_map[c]] = obj;
        // cout << "r: " << r << ", c: " << c << " x_map[r]: " << x_map[r] << ", y_map[c]: " << y_map[c] << " A[" << x_map[r] << "][" << y_map[c] << "] = " << A[x_map[r]][y_map[c]] << endl;
    }
    queue<pair<ll, ll>> que;
    A[x_map[sx]][y_map[sy]] = 0;
    que.push({x_map[sx], y_map[sy]});
    vector<pair<ll, ll>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!que.empty()) {
        auto [x, y] = que.front();
        if (x == x_map[gx] && y == y_map[gy]) {
            cout << "Yes" << endl;
            return 0;
        }
        que.pop();
        for (auto [dx, dy] : directions) {
            ll nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= x_idx || ny < 0 || ny >= y_idx)
                continue;
            if (A[nx][ny] != INF)
                continue;
            // cout << "A[" << nx << "][" << ny << "] = " << A[x][y] + 1 << endl;
            A[nx][ny] = A[x][y] + 1;
            que.push({nx, ny});
        }
    }
    cout << "No" << endl;
}
