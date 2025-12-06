#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N; // ~ 1e9
    ll Q; // 2e5
    cin >> N >> Q;
    ll total_white = N;
    set<pair<ll,ll>> black;
    while (Q--) {
        ll L, R;
        cin >> L >> R;
        auto it = black.lower_bound({L, -1e18});
        if (it != black.begin()) {
            it--;
            if (it->second < L) {
                it++;
            }
        }
        while (it != black.end()) {
            ll cur_l = it->first;
            ll cur_r = it->second;
            if (cur_l > R) break;
            L = min(L, cur_l);
            R = max(R, cur_r);
            total_white += (cur_r - cur_l + 1);
            it = black.erase(it);
        }
        black.insert({L, R});
        total_white -= (R - L + 1);
        cout << total_white << "\n";
    }
}
