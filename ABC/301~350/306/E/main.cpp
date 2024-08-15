#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, K, Q;
	cin >> N >> K >> Q;
	vector<ll> A(Q, 0);
	multiset<ll> m1, m2;
	ll ans = 0;
	for (ll i = 0; i < K; i++)
	{
		m1.insert(0);
	}
	for (ll i = 0; i < N; i++)
	{
		m2.insert(0);
	}
	while (Q--)
	{
		ll X, Y;
		cin >> X >> Y;
		X--;
		if (m1.count(A[X]) > 0)
		{
			m1.erase(m1.find(A[X]));
			m1.insert(Y);
			ans += Y - A[X];
		}
		else
		{
			m2.erase(m2.find(A[X]));
			m2.insert(Y);
		}
		A[X] = Y;
		ll min1 = *m1.begin();
		ll max2 = *m2.rbegin();
		if (min1 < max2)
		{
			m1.erase(m1.begin());
			m1.insert(max2);
			m2.erase(m2.find(max2));
			m2.insert(min1);
			ans += max2 - min1;
		}
		cout << ans << endl;
	}
}
