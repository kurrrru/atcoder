#include <bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
using namespace std;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<ll> B(M);
    for (ll i = 0; i < M; i++) {
        cin >> B[i];
    }
    vector<ll> C = atcoder::convolution(A, B);
    for (ll i = 0; i < C.size(); i++) {
        cout << C[i] << (i == C.size() - 1 ? "\n" : " ");
    }
    return 0;
}
