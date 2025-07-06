#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll rev(vector<ll>& A, ll start, ll end) {
    if (end - start == 1) {
        // if (A[start] > A[end]) {
        //     swap(A[start], A[end]);
        // }
        return {A[start]};
    }
    ll mid = (start + end) / 2;
    auto left = rev(A, start, mid);
    auto right = rev(A, mid, end);
    if (left > right) {
        // for (ll i = start; i < end; i++) {
        //     cout << A[i] << " ";
        // }
        // cout << endl;

        vector<ll> temp(A.begin() + mid, A.begin() + end);
        vector<ll> temp2(A.begin() + start, A.begin() + mid);
        for (ll i = start; i < mid; i++)
            A[i] = temp[i - start];
        for (ll i = mid; i < end; i++)
            A[i] = temp2[i - mid];
        
        
        // for (ll i = start; i < end; i++) {
        //     cout << A[i] << " ";
        // }
        // cout << endl;
        
        
            return right;

        
    }
    return left;
}

int main() {
    ll T;
    cin >> T;
    while (T--) {
        ll N;
        cin >> N;
        vector<ll> A(1 << N);
        for (ll i = 0; i < (1 << N); i++) {
            cin >> A[i];
        }
        ll start = 0, end = (1 << N);
        rev(A, start, end);
        for (ll i = 0; i < (1 << N); i++) {
            cout << A[i] << " \n"[i == (1 << N) - 1];
        }
    }
}