#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    deque<ll> que;
    ll N, Q;
    cin >> N >> Q;
    for (ll i = 0; i < N; ++i) {
        que.push_back(i + 1);
    }
    ll offset = 0;
    while (Q--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll p, x;
            cin >> p >> x;
            que[(offset + p - 1) % N] = x;
        } else if (type == 2) {
            ll p;
            cin >> p;
            cout << que[(offset + p - 1) % N] << endl;
        } else if (type == 3) {
            ll k;
            cin >> k;
            offset = (offset + k) % N;
        }
    }
}
