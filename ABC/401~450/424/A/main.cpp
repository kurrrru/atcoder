#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == b || b == c || c == a) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
