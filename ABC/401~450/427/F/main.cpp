#include <bits/stdc++.h>
using namespace std;
using ll = long long;




void dfs(ll start, ll sum, const ll end, std::map<ll, ll> &m, const std::vector<ll> &A, const ll M) {
    m[sum]++;
    std::map<ll, ll> map1 = m, map2;
    for (ll i = start; i <= end; i++) {
        map2 = m;
        for (auto it = map1.begin(); it != map1.end(); it++) {
            ll new_sum = (it->first + A[i]) % M;
            m[new_sum] += it->second;
        }
        i++;
        map1 = m;
        if (i > end) break;
        for (auto it = map2.begin(); it != map2.end(); it++) {
            ll new_sum = (it->first + A[i]) % M;
            m[new_sum] += it->second;
        }
    }
}


int main() {
    ll N, M;
    cin >> N >> M;
    std::vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    std::map<ll, ll> former, latter;
    std::map<ll, ll> former2, latter2;
    // if (N < 10) {
    //     dfs(0, 0, N - 1, former, A, M);
    //     former[0];
    //     std::cout << former[0] << std::endl;
    //     return 0;
    // }


    ll mid = N / 2;
    dfs(0, 0, mid - 1, former, A, M);
    dfs(mid + 1, 0, N - 1, latter, A, M);
    ll ans = 0;
    for (auto it = former.begin(); it != former.end(); it++) {
        auto [sum, cnt] = *it;
        // std::cout << sum << " " << cnt <<  ", " << latter[(M - sum) % M] << endl;
        ans += cnt * latter[(M - sum) % M];

    }

    // midを使う場合
    dfs(0, 0, mid - 2, former2, A, M);
    dfs(mid + 2, 0, N - 1, latter2, A, M);
    for (auto it = former2.begin(); it != former2.end(); it++) {
        auto [sum, cnt] = *it;
        ans += cnt * latter2[(2 * M - A[mid] - sum) % M];
    }
    cout << ans << endl;



}