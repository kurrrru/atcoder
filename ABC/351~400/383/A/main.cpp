#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	ll water = 0;
	ll t_prev = 0;
	while (N--)
	{
		ll t, v;
		cin >> t >> v;
		water -= min(water, t - t_prev);
		water += v;
		t_prev = t;
	}
	cout << water << endl;
}
