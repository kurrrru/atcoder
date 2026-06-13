#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i =0; i<N; i++) {
        cin >> A[i];
    }
    ll m = 0;
    for (ll i = 0; i < N; i++) {
        if (i + 1 < m || i == 0) {
            m = max(m, i + 1 + A[i]);
        }
    }
    cout << min(N, m - 1) << endl;
}
