#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<pair<ll, ll>> v(N);
    ll minx = 1e9+3, miny = 1e9+3, maxx = -1e9-3, maxy = -1e9-3;
    for (ll i = 0; i < N; ++i) {
        cin >> v[i].first >> v[i].second;
        minx = min(minx, v[i].first);
        miny = min(miny, v[i].second);
        maxx = max(maxx, v[i].first);
        maxy = max(maxy, v[i].second);
    }
    cout << max((maxx - minx + 1) / 2, (maxy - miny + 1) / 2) << endl;

}
