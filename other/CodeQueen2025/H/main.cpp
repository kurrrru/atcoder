#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
ll H, W;

vector<ll> path;
vector<multiset<ll>> edge(H * W);
vector<vector<bool>> visited(H * W);


ll toindex(ll i, ll j) {
    return i * W + j;
}

void dfs(int v) {
    for (auto u : edge[v]) {
        if (!visited[v][u]) {
            visited[v][u] = true;
            visited[u][v] = true;
            dfs(u);
        }
    }

}

int main() {
    cin >> H >> W;
    for (ll i = 0; i < H; i++) {
        for (ll j = 0; j < W; j++) {
            if (i > 0) {
                edge[toindex(i, j)].insert(toindex(i - 1, j));
            }
            if (i < H - 1) {
                edge[toindex(i, j)].insert(toindex(i + 1, j));
            }
            if (j > 0) {
                edge[toindex(i, j)].insert(toindex(i, j - 1));
            }
            if (j < W - 1) {
                edge[toindex(i, j)].insert(toindex(i, j + 1));
            }
        }
    }
    if (H % 2 == 0 && W % 2 == 0) {
        for (ll i = 1; i < H - 1; i += 2) {
            edge[toindex(i, 0)].insert(toindex(i + 1, 0));
            edge[toindex(i, W - 1)].insert(toindex(i + 1, W - 1));
            edge[toindex(i + 1, 0)].insert(toindex(i, 0));
            edge[toindex(i + 1, W - 1)].insert(toindex(i, W - 1));
        }
        for (ll j = 1; j < W - 1; j += 2) {
            edge[toindex(0, j)].insert(toindex(0, j + 1));
            edge[toindex(H - 1, j)].insert(toindex(H - 1, j + 1));
            edge[toindex(0, j + 1)].insert(toindex(0, j));
            edge[toindex(H - 1, j + 1)].insert(toindex(H - 1, j));
        }
    }
    if (H % 2 == 1 && W % 2 == 1) {
        edge[toindex(1, 0)].insert(toindex(1, 1));
        edge[toindex(1, 1)].insert(toindex(1, 0));
        edge[toindex(0, 1)].insert(toindex(1, 1));
        edge[toindex(1, 1)].insert(toindex(0, 1));
        edge[toindex(H - 2, W - 1)].insert(toindex(H - 2, W - 2));
        edge[toindex(H - 2, W - 2)].insert(toindex(H - 2, W - 1));
        edge[toindex(H - 1, W - 2)].insert(toindex(H - 2, W - 2));
        edge[toindex(H - 2, W - 2)].insert(toindex(H - 1, W - 2));

        for (ll i = 2; i < H - 2; i += 2) {
            edge[toindex(i, 0)].insert(toindex(i + 1, 0));
            edge[toindex(i - 1, W - 1)].insert(toindex(i, W - 1));
            edge[toindex(i + 1, 0)].insert(toindex(i, 0));
            edge[toindex(i, W - 1)].insert(toindex(i - 1, W - 1));
        }
        for (ll j = 2; j < W - 2; j += 2) {
            edge[toindex(0, j)].insert(toindex(0, j + 1));
            edge[toindex(H - 1, j - 1)].insert(toindex(H - 1, j));
            edge[toindex(0, j + 1)].insert(toindex(0, j));
            edge[toindex(H - 1, j)].insert(toindex(H - 1, j - 1));
        }
    }

    if (H % 2 == 0 && W % 2 == 1) {
        edge[toindex(1, 0)].insert(toindex(1, 1));
        edge[toindex(1, 1)].insert(toindex(1, 0));
        edge[toindex(0, 1)].insert(toindex(1, 1));
        edge[toindex(1, 1)].insert(toindex(0, 1));
        edge[toindex(H - 2, 0)].insert(toindex(H - 2, 1));
        edge[toindex(H - 2, 1)].insert(toindex(H - 2, 0));
        edge[toindex(H - 1, 1)].insert(toindex(H - 2, 1));
        edge[toindex(H - 2, 1)].insert(toindex(H - 1, 1));
        for (ll i = 2; i < H - 2; i += 2) {
            edge[toindex(i, 0)].insert(toindex(i + 1, 0));
            edge[toindex(i - 1, W - 1)].insert(toindex(i, W - 1));
            edge[toindex(i + 1, 0)].insert(toindex(i, 0));
            edge[toindex(i, W - 1)].insert(toindex(i - 1, W - 1));
        }
        if (H >= 6) {
            edge[toindex(H - 3, W - 1)].insert(toindex(H - 2, W - 1));
            edge[toindex(H - 2, W - 1)].insert(toindex(H - 3, W - 1));
        }
        for (ll j = 2; j < W - 2; j += 2) {
            edge[toindex(0, j)].insert(toindex(0, j + 1));
            edge[toindex(H - 1, j)].insert(toindex(H - 1, j + 1));
            edge[toindex(0, j + 1)].insert(toindex(0, j));
            edge[toindex(H - 1, j + 1)].insert(toindex(H - 1, j));
        }
    }
    if (H % 2 == 1 && W % 2 == 0) {
        edge[toindex(0, 1)].insert(toindex(1, 1));
        edge[toindex(1, 1)].insert(toindex(0, 1));
        edge[toindex(1, 0)].insert(toindex(1, 1));
        edge[toindex(1, 1)].insert(toindex(1, 0));
        edge[toindex(0, W - 2)].insert(toindex(1, W - 2));
        edge[toindex(1, W - 2)].insert(toindex(0, W - 2));
        edge[toindex(1, W - 1)].insert(toindex(1, W - 2));
        edge[toindex(1, W - 2)].insert(toindex(1, W - 1));
        for (ll j = 2; j < W - 2; j += 2) {
            edge[toindex(0, j)].insert(toindex(0, j + 1));
            edge[toindex(H - 1, j - 1)].insert(toindex(H - 1, j));
            edge[toindex(0, j + 1)].insert(toindex(0, j));
            edge[toindex(H - 1, j)].insert(toindex(H - 1, j - 1));
        }
        if (W >= 6) {
            edge[toindex(H - 1, W - 3)].insert(toindex(H - 1, W - 2));
            edge[toindex(H - 1, W - 2)].insert(toindex(H - 1, W - 3));
        }
        for (ll i = 2; i < H - 2; i += 2) {
            edge[toindex(i, 0)].insert(toindex(i + 1, 0));
            edge[toindex(i - 1, W - 1)].insert(toindex(i, W - 1));
            edge[toindex(i + 1, 0)].insert(toindex(i, 0));
            edge[toindex(i, W - 1)].insert(toindex(i - 1, W - 1));
        }
    }

    for (ll i = 0; i < H * W; i++) {
        visited[i].resize(edge[i].size(), false);
    }

    

}
