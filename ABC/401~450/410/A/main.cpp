#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }
    ll K;
    cin >> K;
    ll ans = 0;
    for (ll i = 0; i < N; i++)
    {
        if (A[i] >= K)
            ans++;
    }
    cout << ans << endl;
}
