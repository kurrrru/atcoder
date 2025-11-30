#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    ll T;
    cin >> T;
    while (T--) {
        ll N;
        string S;
        cin >> N >> S;
        ll longest0 = 0, streak = 0, longest1 = 0;
        ll cnt[2] = {0, 0};
        for (int i = 0; i < N; i++) {
            cnt[S[i] - '0']++;
            if (i > 0 && S[i - 1] == S[i]) {
                streak++;
            } else {
                streak = 1;
            }
            if (S[i] == '0' && longest0 < streak) {
                longest0 = streak;
            } else if (S[i] == '1' && longest1 < streak) {
                longest1 = streak;
            }
        }
        cout << min(N - longest0 * 2 + cnt[0], N - longest1 * 2 + cnt[1]) << endl;
    }

}
