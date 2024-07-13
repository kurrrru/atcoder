#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<ll> L(N), R(N);
	for (ll i = 0; i < N; i++)
		cin >> L[i] >> R[i];
	ll sl = 0, sr = 0;
	for (ll i = 0; i < N; i++)
	{
		sl += L[i];
		sr += R[i];
	}
	if (sl > 0 || sr < 0)
	{
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	vector<ll> ans = R;
	ll s = sr;
	for (ll i = 0; i < N; i++)
	{
		ll d = min(s, R[i] - L[i]);
		ans[i] -= d;
		s -= d;
		if (s == 0)
			break;
	}
	for (ll i = 0; i < N; i++)
		cout << ans[i] << " \n"[i == N - 1];
}
