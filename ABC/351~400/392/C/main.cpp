#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<ll> P(N), Q(N);
	for (ll i = 0; i < N; i++)
		cin >> P[i];
	for (ll i = 0; i < N; i++)
		cin >> Q[i];
	vector<ll> A(N);
	for (ll i = 0; i < N; i++)
		A[Q[i] - 1] = P[i];
	for (ll i = 0; i < N; i++)
		cout << Q[A[i] - 1] << " \n"[i == N - 1];
}
