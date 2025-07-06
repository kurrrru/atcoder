#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll T;
    cin >> T;
    while (T--) {
        ll N;
        cin >> N;
        vector<ll> A(N);
        for (ll i = 0; i < N; i++) {
            cin >> A[i];
        }
        bool all_same = true;
        ll plus_count = 0, minus_count = 0;
        for (ll i = 0; i < N; i++) {
            if (abs(A[i]) != abs(A[0])) {
                all_same = false;
            }
            if (A[i] > 0) {
                plus_count++;
            } else if (A[i] < 0) {
                minus_count++;
            }
        }
        if (all_same && (abs(plus_count - minus_count) <= 1)) {
            cout << "Yes" << endl;
            continue;
        }

        sort(A.begin(), A.end(), [](ll a, ll b) {
            return abs(a) < abs(b);
        });
        bool flag = true;
        for (ll i = 2; i < N; i++) {
            if (A[i - 1] * A[i - 1] != A[i] * A[i - 2]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}