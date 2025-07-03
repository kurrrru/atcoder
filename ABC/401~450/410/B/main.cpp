#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> X(Q);
    for (ll i = 0; i < Q; ++i) {
        cin >> X[i];
    }
    vector<ll> Y(N);
    for (ll i = 0; i < Q; ++i) {
        ll min_index = 0;
        if (X[i] > 0)
            min_index = X[i] - 1;
        else {
            for (ll j = 0; j < N; ++j) {
                if (Y[j] < Y[min_index]) {
                    min_index = j;
                }
            }
        }
        Y[min_index]++;
        cout << min_index + 1 << " \n"[i == Q - 1];
    }

}
