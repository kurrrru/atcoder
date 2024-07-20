#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, T, P;
	cin >> N >> T >> P;
	vector<ll> L(N);
	for (ll i = 0; i < N; ++i)
		cin >> L[i];
	sort(L.begin(), L.end(), greater<ll>());
	cout << max(0ll, T - L[P - 1]) << endl;
}
