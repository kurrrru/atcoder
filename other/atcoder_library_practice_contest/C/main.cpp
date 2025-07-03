#include <bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
using namespace std;

// \sum_{i=0}^{N-1} floor((A*i + B) / M)を計算する

int main() {
    ll T;
    cin >> T;
    while (T--) {
        ll N, M, A, B;
        cin >> N >> M >> A >> B;
        ll floor_sum = atcoder::floor_sum(N, M, A, B);
        cout << floor_sum << endl;
    }
}