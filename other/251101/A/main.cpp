#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N, M;
    cin >> N >> M;
    // sm+e
    map<pair<ll,ll>, ll> m;
    for (ll i = 0; i < N; i++) {
        ll s,e;
        cin >> s >> e;
        m[make_pair(s*M+e,i)]=i+1;
    }
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->second << " ";
    }
    std::cout << endl;
}