#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, A;
	cin >> N >> A;
	vector<ll> T(N);
	for (ll i = 0; i < N; ++i)
		cin >> T[i];
	ll ans = 0;
	for (ll i = 0; i < N; i++)
	{
		if (T[i] >= ans)
			ans = T[i] + A;
		else
			ans += A;
		cout << ans << endl;
	}
}
