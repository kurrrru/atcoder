#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> H(N), B(M);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    sort(B.begin(), B.end());
    sort(H.begin(), H.end());
    int left = 0;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll tmp = left;
        while (tmp < M && H[i] > B[tmp]) {
            tmp++;
        }
        if (tmp == M) break;
        left = tmp + 1;
        ans++;
    }
    if (ans >= K) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
