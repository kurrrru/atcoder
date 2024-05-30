#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<tuple<ll, ll>> sec; // (pos, s/g)
	for (ll i = 0; i < N; i++)
	{
		ll s, g;
		cin >> s >> g;
		sec.push_back(make_tuple(s, 0));
		sec.push_back(make_tuple(g, 1));
	}
	sort(sec.begin(), sec.end());
	ll now_open = 0;
	ll ans = 0;
	for (ll i = 0; i < 2 * N; i++)
	{
		if (get<1>(sec[i]) == 0)
		{
			ans += now_open;
			now_open++;
		}
		else
			now_open--;
	}
	cout << ans << endl;
	return (0);
}
