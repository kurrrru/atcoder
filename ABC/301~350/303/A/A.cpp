# include <bits/stdc++.h>
using namespace std;

bool same(char a, char b) {
    if (a == b) return true;
    if ((a == '1') && (b == 'l')) return true;
    if ((a == 'l') && (b == '1')) return true;
    if ((a == '0') && (b == 'o')) return true;
    if ((a == 'o') && (b == '0')) return true;
    return false;
}

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    string ans = "Yes";

    for (int i = 0; i < n; i++) {
        if (! same(s[i], t[i])) {
            ans = "No"s;
            break;
        }
    }

    cout << ans << endl;
    return 0;
    
}