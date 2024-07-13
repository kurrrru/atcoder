#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	ll a;
	vector<ll> C(1000001, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		C[a]++;
	
	}
	for (int i = 1; i < 1000001; i++)
		C[i] += C[i - 1];
	ll ans = 0, d;
	for (int i = 1; i < 1000001; i++)
	{
		d = C[i] - C[i - 1];
		if (d == 0)
			continue;
		for (int j = i; j < 1000001; j += i)
			ans += (j / i) * (C[min(j + i - 1, 1000000)] - C[j - 1]) * d;
		ans -= d * (d + 1) / 2;
	}
	cout << ans << endl;
}
