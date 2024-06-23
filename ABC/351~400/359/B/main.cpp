#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<ll> A(2 * N);
	for (ll i = 0; i < 2 * N; i++)
	{
		cin >> A.at(i);
	}
	ll ans = 0;
	for (ll i = 0; i < 2 * N - 2; i++)
	{
		if (A[i] == A[i + 2])
			ans++;
	}
	cout << ans << endl;
}
