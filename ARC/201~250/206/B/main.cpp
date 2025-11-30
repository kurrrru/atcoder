#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

#define int long long

int LIS(std::vector<int> &a)
{
	constexpr int inf = 1 << 30;
	const int n = a.size();
	std::vector<int> dp(n, inf);
	for (int i = 0; i < n; i++)
		*lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
	return lower_bound(dp.begin(), dp.end(), inf) - dp.begin();
}

signed main() {
    ll N;
    cin >> N;
    vector<ll> P(N), C(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    vector<vector<ll>> col(N + 1);
    for (int i = 0; i < N; i++) {
        col[C[i]].push_back(P[i]);
    }
    ll cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (col[i].size() == 0) continue;
        int rem = col[i].size() - LIS(col[i]);
        cnt += rem * i;
    }
    cout << cnt << endl;
}
