#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    ll Q;
    cin >> Q;
    while (Q--) {
        string w;
        cin >> w;
        bool takahashi = true, aoki = true;
        for (int i = 0; i < w.size();i++) {
            if (S.find(w[i]) == string::npos) {
                takahashi = false;
            }
            if (T.find(w[i]) == string::npos) {
                aoki = false;
            }
        }
        if (takahashi && !aoki) {
            cout << "Takahashi" << endl;
        } else if (!takahashi && aoki ) {
            cout << "Aoki" << endl;
        } else {
            cout << "Unknown" << endl;
        }
    }
    
}
