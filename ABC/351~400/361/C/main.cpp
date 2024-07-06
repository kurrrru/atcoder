#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, K;
	cin >> N >> K;
	vector<ll> A(N);
	for (ll i = 0; i < N; i++) cin >> A[i];
	sort(A.begin(), A.end());
	ll ans = A[N - 1] - A[0];
	for (ll i = 0; i <= K; i++)
		ans = min(ans, A[i + N - K - 1] - A[i]);
	cout << ans << endl;
}
