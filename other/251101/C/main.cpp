#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    if (N % 2 == 0) {
        for (ll i = 0; i < N; i++) {
            for (ll j = 0; j < N; j++) {
                std::cout << N * i + j + 1 << " ";
            }
            std::cout << endl;
        }
    } else {
        for (ll i = 0; i < N; i++) {
            for (ll j = 0; j < N; j++) {
                if ((i == N / 2 && j == N - 1) || (i == N -1 && j == N / 2)) {
                    std::cout << N * j + i + 1 << " ";
                }else {
                std::cout << N * i + j + 1 << " ";
                }
            }
            std::cout << endl;
        }
    }

}
