#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, M;
	cin >> N >> M;
	vector<ll> A(N);
	for (ll i = 0; i < N; ++i)
		cin >> A[i];
	vector<ll> B(M);
	for (ll i = 0; i < M; ++i)
		cin >> B[i];
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	ll ans = 0;
	ll idx_A = 0;
	for (ll i = 0; i < M; i++)
	{
		while (idx_A < N && A[idx_A] < B[i])
			idx_A++;
		if (idx_A == N)
		{
			cout << -1 << endl;
			return 0;
		}
		if (A[idx_A] >= B[i])
		{
			ans += A[idx_A];
			idx_A++;
		}
	}
	cout << ans << endl;
}
