#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class BIT {
    vector<ll> bit;
    int n;

public:
    BIT(int size) : n(size), bit(size + 1, 0) {}

    void add(int idx, ll val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    ll sum(int idx) {
        ll s = 0;
        for (; idx > 0; idx -= idx & -idx)
            s += bit[idx];
        return s;
    }
};

int main() {
    ll N;
    cin >> N;
    vector<ll> P(N);
    vector<pair<ll, ll>> indexed_P(N);

    for (ll i = 0; i < N; i++) {
        cin >> P[i];
        indexed_P[i] = {P[i], i + 1}; // 値とインデックスを保持
    }

    sort(indexed_P.begin(), indexed_P.end());

    BIT bit(N);
    ll ans = 0;

    for (auto [value, idx] : indexed_P) {
        ans += bit.sum(idx - 1); // 現在のインデックスより小さい要素の和
        bit.add(idx, idx);       // BITにインデックス値を追加
    }

    cout << ans << endl;
}
