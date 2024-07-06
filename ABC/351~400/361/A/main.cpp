#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, K, X;
	cin >> N >> K >> X;
	vector<ll> A(N);
	for (ll i = 0; i < N; i++) cin >> A[i];
	for (ll i = 0; i < N; i++)
	{
		if (i == K)
			cout << X << " ";
		cout << A[i];
		cout << " \n"[i == N - 1 && K != N];
	}
	if (K == N)
		cout << X << endl;
}
