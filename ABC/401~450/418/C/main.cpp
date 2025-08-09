#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<ll> acc(N + 1, 0);
    for (ll i = 0; i < N; ++i) {
        acc[i + 1] = acc[i] + A[i];
    }
    while (Q--) {
        ll b;
        cin >> b;
        ll b_lo = lower_bound(A.begin(), A.end(), b) - A.begin();
        if (b_lo == N) {
            cout << -1 << endl;
            continue;
        }
        ll ans = acc[b_lo] + (N - b_lo) * (b - 1) + 1;
        cout << ans << endl;
    }
}