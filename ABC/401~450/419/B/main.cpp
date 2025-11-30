#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll Q;
    cin >> Q;
    multiset<ll> m;
    while (Q--)
    {
        ll op;
        cin >> op;
        if (op == 1) {
            ll x;
            cin >> x;
            m.insert(x);
        } else if (op == 2) {
            cout << *m.begin() << endl;
            m.erase(m.begin());
        }
    }
}
