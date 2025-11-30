#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    int c[256] = {};
    for (int i = 0; i < S.length(); i++) {
        c[S[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (c[i] == 1)
            cout << (char)i << endl;
    }
}
