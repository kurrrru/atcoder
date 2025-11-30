#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main () {
    ll N;
    cin >> N;
    if (N <= 2) {
        cout << "First" << endl;
        cout << N << endl;
        return 0;
    }
    vector<bool> win_first(N + 1, false);
    win_first[1] = true;
    win_first[2] = true;
    for (ll i = 3; i <= N; i++) {
        win_first[i] = !(win_first[i - 1] && win_first[i - 2]);
    }
    // for (ll i = 0; i <= N; i++) {
    //     cout << win_first[i] << endl;
    // }
    bool first = win_first[N];
    if (first) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    ll rem = N;
    if (first) {
        if (!win_first[N - 1]){
            cout << 1 << endl;
            rem -= 1;
        } else {
            cout << 2 << endl;
            rem -= 2;
        }
    }
    while (rem > 0) {
        ll x;
        cin >> x;
        rem -= x;
        ll eat = (!win_first[rem - 1]) ? 1 : 2;
        cout << eat << endl;
        rem -= eat;
    }

}