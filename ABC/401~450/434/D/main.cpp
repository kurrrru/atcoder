#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> U(N), D(N), L(N), R(N);
    for (int i = 0; i < N; i++) {
        cin >> U[i] >> D[i] >> L[i] >> R[i];
        U[i]--, D[i]--, L[i]--, R[i]--;
    }
    vector<vector<ll>> sky(2001, vector<ll>(2001, 0));

    for (int i = 0; i < N; i++) {
        sky[U[i]][L[i]]++;
        sky[U[i]][R[i] + 1]--;
        sky[D[i] + 1][L[i]]--;
        sky[D[i] + 1][R[i] + 1]++;
    }
    for (int i = 1; i < 2001; i++) {
        sky[0][i] += sky[0][i - 1];
    }
    for (int i = 1; i < 2001; i++) {
        sky[i][0] += sky[i - 1][0];
        for (int j = 1; j < 2001; j++) {
            sky[i][j] += sky[i - 1][j] + sky[i][j - 1] - sky[i - 1][j - 1];
        }
    }
    vector<vector<ll>> sky1(2001, vector<ll>(2001, 0));
    int total = 0;
    for (int i = 0; i < 2001; i++) {
        for (int j = 0; j < 2001; j++) {
            if (sky[i][j] == 1) {
                sky1[i + 1][j + 1] = 1;
            }
            if (sky[i][j] > 0) { 
                total++;
            }
        }
    }
    for (int i = 1; i < 2001; i++) {
        sky1[0][i] += sky1[0][i - 1];
    }
    for (int i = 1; i < 2001; i++) {
        sky1[i][0] += sky1[i - 1][0];
        for (int j = 1; j < 2001; j++) {
            sky1[i][j] += sky1[i - 1][j] + sky1[i][j - 1] - sky1[i - 1][j - 1];
        }
    }
    for (int i = 0; i < N; i++) {
        ll ans = 2000 * 2000 - total;
        ans += sky1[D[i] + 1][R[i] + 1] - sky1[D[i] + 1][L[i]] - sky1[U[i]][R[i] + 1] + sky1[U[i]][L[i]];
        std::cout << ans << endl;
    }

    
    
}
