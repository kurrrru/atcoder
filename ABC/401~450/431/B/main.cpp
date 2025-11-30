#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int X, N, Q;
    cin >> X >> N;
    vector<int> W(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }
    cin >> Q;
    vector<bool> on(N);
    int ans = X;
    while (Q--) {
        int P;
        cin >> P;
        P--;
        if (on[P]) {
            ans -= W[P];
            on[P] = false;
        } else {
            ans += W[P];
            on[P] = true;
        }
        cout << ans << endl;
    }

}
