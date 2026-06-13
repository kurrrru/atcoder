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
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            ll sum = 0;
            for (int k = i; k <= j; k++) {
                sum += A[k];
            }
            bool div = false;
            for (int k = i; k <= j; k++) {
                if (sum % A[k] == 0) {
                    div = true;
                    break;
                }
            }
            if (!div) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
