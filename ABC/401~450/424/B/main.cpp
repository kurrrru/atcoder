#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> X(N + 1);
    while (K--) {
        int A, B;
        cin >> A >> B;
        X[A]++;
        if (X[A] == M) {
            cout << A << " ";
        }
    }
    cout << endl;

}
