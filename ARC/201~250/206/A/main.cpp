#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll cnt = N * (N - 1) / 2 + 1;
    vector<ll> cnts(2000001, 0);
    for (ll i = 0; i < N; i++) {
        if (i > 0 && A[i] == A[i - 1]) {
            cnt -= N - i + cnts[A[i]] - 1;
            continue;
        }
        cnt -= cnts[A[i]];
        cnts[A[i]]++;
    }
    // for (ll i = 0; i <= 2000000; i++) {
    //     cnt -= cnts[i] * (cnts[i] - 1) / 2;
    // }
    cout << cnt << endl;
}
