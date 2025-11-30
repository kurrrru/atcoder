#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> X(N), R(N);
    map<ll,set<ll>> s1,s2;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> R[i];
        s1[X[i] + R[i]].insert(i);
        s1[X[i] - R[i]].insert(i);
    }
    vector<bool> used(N);
    ll ans = 0;
    for (auto it = s1.begin(); it != s1.end(); it++) {
        auto it2 = it;
        while (it2->second.size() == 1) {
            ll idx = *(it2->second.begin());
            it2->second.erase(idx);
            used[idx] = true;
            ans++;
            ll other;
            if (it2->first == X[idx] + R[idx]) {
                other = X[idx] - R[idx];
            } else {
                other = X[idx] + R[idx];
            }
            s1[other].erase(idx);
            it2 = s1.find(other);
        }
    }
    for (auto it = s1.begin(); it != s1.end(); it++) {
        if (it->second.size() > 0) {
            ans ++;
        }
    }
    cout << ans << endl;

}
