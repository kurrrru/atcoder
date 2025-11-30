#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll M, N;
    cin >> N >> M;
    vector<ll> A(N), B(N);
    for (int i =0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    for (int i = 0; i < M; i++) {
        double total = 0;
        double cnt = 0;
            
        for (int j = 0; j < N; j++) {
            if (A[j] - 1 == i) {
                total += B[j];
                cnt++;
            }
        }
        cout << setprecision(10) << total / cnt << endl;
    }
}
