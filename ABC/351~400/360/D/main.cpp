#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int N, T;
	cin >> N >> T;
	string S;
	cin >> S;
	vector<ll> p, m;
	for (int i = 0; i < N; i++)
	{
		ll x;
		cin >> x;
		if (S[i] == '1')
			p.push_back(x);
		else
			m.push_back(x);
	}
	sort(p.begin(), p.end());
	sort(m.begin(), m.end());
	ll ans = 0;
	for (int i = 0; i < p.size(); i++)
	{
		ans += upper_bound(m.begin(), m.end(), p[i] + 2 * T) - upper_bound(m.begin(), m.end(), p[i]);
	}
	cout << ans << endl;
}
