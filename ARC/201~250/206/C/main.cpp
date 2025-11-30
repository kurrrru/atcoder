#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
ll N;
cin >> N;
vector<ll> A(N);
for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i]--;
}
vector<int> state(N, 0); // 0: unknown, 1: forward, -1: backward, 2: other
ll other_cnt = 0;
for (int i = 0; i < N - 1; i++) {
    if (A[i] == -2) {
        continue;
    }
    if (A[i] == i + 1) {
        state[i] = 1;
    } else if (A[i] == i - 1) {
        state[i] = -1;
    } else {
        other_cnt++;
        state[i] = 2;
    }
}
if (other_cnt >= 2) {
    cout << 0 << endl;
    return 0;
}
ll start = 0;
ll last_state = 0;
for (int i = 0; i < N; i++) {
    if (state[i] == 1) {
        if (last_state == -1 || last_state == 2) {
            cout << 0 << endl;
            return 0;
        }
        for (int j = start; j < i; j++) {
            state[j] = 1;
        }
        start = i + 1;
        last_state = 1;
    } else if (state[i] == -1) {
        if (other_cnt == 1 && last_state == 1) {
            cout << 0 << endl;
            return 0;
        }
        if (last_state == 2 || other_cnt == 1) {
            for (int j = start; j < i; j++) {
                state[j] = -1;
            }
            start = i + 1;
            last_state = -1;
        }
    } else if (state[i] == 2) {
        start = i + 1;
        last_state = 2;
    }
}
if (last_state == 1 && other_cnt == 1) {
    cout << 0 << endl;
    return 0;
}
if (last_state == -1) {
    for (int j = start; j < N; j++) {
        state[j] = -1;
    }
}
if (other_cnt == 1) {
    cout << 1 << endl;
    return 0;
}
ll cnt_0 = std::count(state.begin(), state.end(), 0);
cout << cnt_0 * N - (cnt_0 - 1) << endl;

}
