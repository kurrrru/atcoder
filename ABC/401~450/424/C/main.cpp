#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    vector<vector<ll>> edges(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        if (A[i] >= 0)
            edges[A[i]].push_back(i);
        if (B[i] >= 0)
            edges[B[i]].push_back(i);
    }
    vector<bool> visited(N, false);
    for (ll i = 0; i < N; i++) {
        if (visited[i]) continue;
        if (A[i] != -1 || B[i] != -1)
            continue;
        stack<ll> st;
        st.push(i);
        visited[i] = true;
        while (!st.empty()) {
            ll v = st.top();
            st.pop();
            for (ll nv : edges[v]) {
                if (visited[nv]) continue;
                visited[nv] = true;
                st.push(nv);
            }
        }
    }
    ll cnt = 0;
    for (ll i = 0; i < N; i++) {
        if (visited[i]) {
            cnt++;
        }
    }
    cout << cnt << endl;
}
