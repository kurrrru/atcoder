#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, D;
	cin >> N >> D;
	vector<ll> x(N), y(N);
	for (ll i = 0; i < N; i++)
		cin >> x[i] >> y[i];
	vector<ll> s(D + 1, 0), t(D + 1, 0);
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	vector<ll> acc_x(N + 1), acc_y(N + 1);
	for (ll i = 0; i < N; i++)
	{
		acc_x[i + 1] = acc_x[i] + x[i];
		acc_y[i + 1] = acc_y[i] + y[i];
	}
	vector<ll> man_x(4000002), man_y(4000002); // [-2000000, 2000000]
	man_x[0] = acc_x[N] - acc_x[0] + 2000000 * N;
	man_y[0] = acc_y[N] - acc_y[0] + 2000000 * N;
	ll idx_x = 0, idx_y = 0;
	for (ll i = 1; i <= 4000000; i++)
	{
		man_x[i] = man_x[i - 1] + idx_x - (N - idx_x);
		while (idx_x < N && x[idx_x] == i - 2000000)
			idx_x++;
		man_y[i] = man_y[i - 1] + idx_y - (N - idx_y);
		while (idx_y < N && y[idx_y] == i - 2000000)
			idx_y++;
	}
	for (ll i = 0; i <= 4000000; i++)
	{
		if (man_x[i] <= D)
		{
			s[man_x[i]]++;
			// cout << i << " " << man_x[i] << endl;
		}
		if (man_y[i] <= D)
			t[man_y[i]]++;
	}
	for (ll i = 1; i <= D; i++)
	{
		// s[i] += s[i - 1];
		t[i] += t[i - 1];
	}
	// cout << "s: ";
	// for (ll i = 0; i <= D; i++)
	// 	cout << s[i] << " ";
	// cout << endl;
	// cout << "t: ";
	// for (ll i = 0; i <= D; i++)
	// 	cout << t[i] << " ";
	// cout << endl;
	ll ans = 0;
	for (ll i = 0; i <= D; i++)
	{
		ans += s[i] * t[D - i];
	}
	cout << ans << endl;
}
