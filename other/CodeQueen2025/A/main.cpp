#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<pair<ll, ll>> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A.begin(), A.end());
    for (ll i = 0; i < N; i++) {
        cout << A[i].first << " " << A[i].second << endl;
    }
}
