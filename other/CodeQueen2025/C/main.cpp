#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;
    ll mod = 998244353;
    ll ans = 1;
    for (ll i = 1; i <= K; i++) {
        ans *= i;
        ans %= mod;
    }
    for (ll i = 1; i <= N - K; i++) {
        ans *= K + 1;
        ans %= mod;
    }
    cout << ans << endl;
}
