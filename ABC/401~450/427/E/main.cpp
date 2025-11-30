#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll H, W;
    cin >> H >> W;
    std::vector<std::string> S(H);
    for (ll i = 0; i < H; i++) {
        cin >> S[i];
    }
    queue<pair<ll, std::vector<std::string>>> q;
    q.push({0, S});
    std::set<std::vector<std::string>> visited;
    visited.insert(S);
    ll ans = 0;
    while (!q.empty()) {
        auto [mv_cnt, grid] = q.front();
        q.pop();
        bool trash_found = false;
        for (ll i = 0; i < H; i++) {
            for (ll j = 0; j < W; j++) {
                if (grid[i][j] == '#') {
                    trash_found = true;
                    break;
                }
            }
            if (trash_found)
                break;
        }
        if (!trash_found) {
            std::cout << mv_cnt << std::endl;
            return 0;
        }
        // up i-1
        std::vector<std::string> newgrid(H, std::string(W, '.'));
        bool failed = false;
        for (ll i = 0; i < H; i++) {
            for (ll j = 0; j < W; j++) {
                if (grid[i][j] == 'T') {
                    if (newgrid[i][j] == '.') {
                        newgrid[i][j] = 'T';
                    } else if (newgrid[i][j] == '#') {
                        failed = true;
                        break;
                    }
                } else if (grid[i][j] == '#') {
                    if (i == 0) {
                        continue;
                    } else if (newgrid[i - 1][j] == '.') {
                        newgrid[i - 1][j] = '#';
                    } else {
                        failed = true;
                        break;
                    }
                }
            }
            if (failed)
                break;
        }
        if (!failed && visited.count(newgrid) == 0) {
            visited.insert(newgrid);
            q.push({mv_cnt + 1, newgrid});
        }

        // down i+1
        newgrid.assign(H, std::string(W, '.'));
        failed = false;
        for (ll i = 0; i < H; i++) {
            for (ll j = 0; j < W; j++) {
                if (grid[i][j] == 'T') {
                    if (newgrid[i][j] == '.') {
                        newgrid[i][j] = 'T';
                    } else if (newgrid[i][j] == '#') {
                        failed = true;
                        break;
                    }
                } else if (grid[i][j] == '#') {
                    if (i == H - 1) {
                        continue;
                    } else if (newgrid[i + 1][j] == '.') {
                        newgrid[i + 1][j] = '#';
                    } else {
                        failed = true;
                        break;
                    }
                }
            }
            if (failed)
                break;
        }
        if (!failed && visited.count(newgrid) == 0) {
            visited.insert(newgrid);
            q.push({mv_cnt + 1, newgrid});
        }
        // left j-1
        newgrid.assign(H, std::string(W, '.'));
        failed = false;
        for (ll i = 0; i < H; i++) {
            for (ll j = 0; j < W; j++) {
                if (grid[i][j] == 'T') {
                    if (newgrid[i][j] == '.') {
                        newgrid[i][j] = 'T';
                    } else if (newgrid[i][j] == '#') {
                        failed = true;
                        break;
                    }
                } else if (grid[i][j] == '#') {
                    if (j == 0) {
                        continue;
                    } else if (newgrid[i][j - 1] == '.') {
                        newgrid[i][j - 1] = '#';
                    } else {
                        failed = true;
                        break;
                    }
                }
            }
        }
        if (!failed && visited.count(newgrid) == 0) {
            visited.insert(newgrid);
            q.push({mv_cnt + 1, newgrid});
        }
        // right j+1
        newgrid.assign(H, std::string(W, '.'));
        failed = false;
        for (ll i = 0; i < H; i++) {
            for (ll j = 0; j < W; j++) {
                if (grid[i][j] == 'T') {
                    if (newgrid[i][j] == '.') {
                        newgrid[i][j] = 'T';
                    } else if (newgrid[i][j] == '#') {
                        failed = true;
                        break;
                    }
                } else if (grid[i][j] == '#') {
                    if (j == W - 1) {
                        continue;
                    } else if (newgrid[i][j + 1] == '.') {
                        newgrid[i][j + 1] = '#';
                    } else {
                        failed = true;
                        break;
                    }
                }
            }
        }
        if (!failed && visited.count(newgrid) == 0) {
            visited.insert(newgrid);
            q.push({mv_cnt + 1, newgrid});
        }
    }
    std::cout << -1 << std::endl;
}

