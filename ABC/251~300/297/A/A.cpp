# include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long d;
    cin >> n >> d;
    vector<long long> t(n);
    cin >> t.at(0);
    for (int i = 1; i < n; i++) {
        cin >> t.at(i);
        if (t.at(i) - t.at(i - 1) <= d) {
            cout << t.at(i) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}