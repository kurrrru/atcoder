#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll A, B, C, D, E, F;
	ll N;
	cin >> A >> B >> C >> D >> E >> F >> N;
	vector<ll> X(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> X[i];
	}
	for (ll i = 0; i < N; i++)
	{
		if (X[i] >= 500 && F > 0)
		{
			ll t = min(X[i] / 500, F);
			F -= t;
			X[i] -= 500 * t;
		}
		if (X[i] >= 100 && E > 0)
		{
			ll t = min(X[i] / 100, E);
			E -= t;
			X[i] -= 100 * t;
		}
		if (X[i] >= 50 && D > 0)
		{
			ll t = min(X[i] / 50, D);
			D -= t;
			X[i] -= 50 * t;
		}
		if (X[i] >= 10 && C > 0)
		{
			ll t = min(X[i] / 10, C);
			C -= t;
			X[i] -= 10 * t;
		}
		if (X[i] >= 5 && B > 0)
		{
			ll t = min(X[i] / 5, B);
			B -= t;
			X[i] -= 5 * t;
		}
		if (X[i] >= 1 && A > 0)
		{
			ll t = min(X[i], A);
			A -= t;
			X[i] -= t;
		}
		if (X[i] > 0)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}