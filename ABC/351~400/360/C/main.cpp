#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<ll> A(N, 0), W(N, 0);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> W[i];
	ll ans = 0;
	vector<ll> h(N + 1, 0);
	for (int i = 0; i < N; i++)
	{
		ans += min(h[A[i]], W[i]);
		h[A[i]] = max(h[A[i]], W[i]);
	}
	cout << ans << endl;
}
