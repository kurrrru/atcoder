#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<string> S(N);
    for (ll i = 0; i < N; i++) {
        cin >> S[i];
    }
    set<string> T;
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            if (i == j) continue;
            string s = S[i] + S[j];
            T.insert(s);
        }
    }
    cout << T.size() << endl;
}