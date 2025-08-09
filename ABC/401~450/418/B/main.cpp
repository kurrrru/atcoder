#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    double ans = 0.0;
    for (int i = 0; i < N; ++i) {
        if (S[i] != 't')
            continue;
        for (int j = i + 1; j < N; ++j) {
            if (S[j] != 't')
                continue;
            ll tcnt = 0;
            for (int k = i + 1; k < j; ++k) {
                if (S[k] == 't') {
                    ++tcnt;
                }
            }
            ans = max(ans, (double)tcnt / (j - i - 1));
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
}