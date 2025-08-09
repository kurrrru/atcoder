#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    ll N, S;
    cin >> N >> S;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    ll count = 0;
    for (ll i = 0; i < N; i++) {
        count += (upper_bound(A.begin(), A.end(), S - A[i]) - lower_bound(A.begin(), A.end(), S - A[i]));
    }
    if (S % 2 == 0) {
        count -= (upper_bound(A.begin(), A.end(), S / 2) - lower_bound(A.begin(), A.end(), S / 2));
    }
    cout << count / 2 << endl;
}
