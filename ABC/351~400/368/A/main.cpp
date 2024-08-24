#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, K;
	cin >> N >> K;
	vector<ll> A(N);
	for (ll i = 0; i < N; ++i)
		cin >> A[i];
	for (ll i = N - K; i < 2 * N - K; ++i)
	{
		if (i < N)
			cout << A[i] << " \n"[i == 2 * N - K - 1];
		else
			cout << A[i - N] << " \n"[i == 2 * N - K - 1];
	}
}
