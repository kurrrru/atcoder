#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, K, X;
    cin >> N >> K >> X;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end(), std::greater<ll>());
    ll total_min = 0;
    for (int i = N - K; i < N; i++) {
        total_min += A[i];
        if (total_min >= X) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;


}
