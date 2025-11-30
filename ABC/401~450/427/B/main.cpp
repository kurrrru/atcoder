#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    ll a = 1;
    std::string s;
    for (ll i = 0; i < N - 1; i++) {
        s = to_string(a);
        for (ll j = 0; j < s.size(); j++) {
            a += (s[j] - '0');
        }
    }
    cout << a << endl;
}