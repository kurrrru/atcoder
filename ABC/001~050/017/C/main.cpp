#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, M;
	cin >> N >> M;
	vector<ll> A(M + 1, 0);
	ll l, r, s;
	ll total = 0, min_A = 0;
	for (ll i = 0; i < N; ++i)
	{
		cin >> l >> r >> s;
		--l, --r;
		A[l] += s;
		A[r + 1] -= s;
		total += s;
	}
	min_A = A[0];
	for (ll i = 1; i < M; ++i)
	{
		A[i] += A[i - 1];
		min_A = min(min_A, A[i]);
	}
	cout << total - min_A << endl;
}
