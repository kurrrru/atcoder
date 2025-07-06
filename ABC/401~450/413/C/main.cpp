#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll Q;
    cin >> Q;
    vector<pair<ll, ll>> que;
    ll start = 0;
    while (Q--) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll c, x;
            cin >> c >> x;
            que.push_back({c, x});
        } else if (op == 2) {
            ll k;
            cin >> k;
            ll sum = 0;
            ll idx = start;
            while (idx < que.size() && k > 0) {
                if (que[idx].first <= k) {
                    sum += que[idx].second * que[idx].first;
                    k -= que[idx].first;
                    start++;
                } else {
                    sum += que[idx].second * k;
                    que[idx].first -= k;
                    break;
                }
                idx++;
            }
            cout << sum << endl;

        }
    }
}