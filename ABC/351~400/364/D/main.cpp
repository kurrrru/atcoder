#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, Q;
	cin >> N >> Q;
	vector<ll> A(N);
	for (ll i = 0; i < N; i++)
		cin >> A[i];
	sort(A.begin(), A.end());
	while (Q--)
	{
		ll b, k;
		cin >> b >> k;
		ll pos = lower_bound(A.begin(), A.end(), b) - A.begin();
		if (pos == N)
		{
			cout << b - A[N - k] << endl;
		}
		else
		{
			ll l = pos - 1;
			ll r = N;
			while (r - l > 1)
			{
				ll m = (l + r) / 2;
				bool ok = false;
				if (m - k + 1 >= 0 && A[m] - b >= b - A[m - k + 1])
					ok = true;
				if (ok)
					r = m;
				else
					l = m;
			}
			if (r - k < 0)
				cout << A[r] - b << endl;
			else if (r == N)
				cout << b - A[r - k] << endl;
			else
				cout << min(A[r] - b, b - A[r - k]) << endl;
		}
	}
}
