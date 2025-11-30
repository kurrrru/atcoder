#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll T;
    cin >> T;
    while (T--) {
        ll N, H;
        cin >> N >> H;
        vector<ll> t(N), l(N), u(N);
        for (int i = 0; i < N; i++) {
            cin >> t[i] >> l[i] >> u[i];
        }
        ll hi = H, lo = H;
        ll last = 0;
        bool ans = true;
        for (int i = 0; i < N; i++) {
            hi = hi + (t[i] - last);
            lo = max(1ll, lo - (t[i] - last));
            last = t[i];

            hi = min(hi, u[i]);
            lo = max(lo, l[i]);
            // std::cout << hi << " " << lo << endl;
            if (hi < lo) {
                ans = false;
                break;
            }
        }
        std::cout << (ans ? "Yes" : "No") <<endl;
    }
}
