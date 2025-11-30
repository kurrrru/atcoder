#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll M;
    cin >> M;
    map<ll, ll> m;
    for (ll i = 0; i < M; i++) {
        ll s = (i * i % M) * i % M;
        m[s] = i;
    }
    for (ll i = 0; i < M; i++) {
        if (m.count(i) == 0) {
            std::cout << -1 << endl;
        } else {
            cout << m[i] << endl;
        }
    }
}