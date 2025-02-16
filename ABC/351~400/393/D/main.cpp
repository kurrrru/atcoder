#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	string S;
	cin >> S;
	ll cnt_one = 0;
	for (ll i = 0; i < N; i++)
	{
		if (S[i] == '1')
			cnt_one++;
	}
	ll l = 0, r = N - cnt_one;
	while (l < r - 2)
	{
		ll m1 = l + (r - l) / 3;
		ll m2 = r - (r - l) / 3;
		ll cnt_one_m1 = 0, cnt_one_m2 = 0;
		ll cnt_1 = 0, cnt_2 = 0;
		ll idx_1 = m1, idx_2 = m2;
		for (ll i = 0; i < N; i++)
		{
			if (S[i] == '1')
			{
				cnt_1 += abs(i - idx_1);
				cnt_2 += abs(i - idx_2);
				idx_1++;
				idx_2++;
			}
		}
		// cout << "l: " << l << " r: " << r << endl;
		// cout << "m1: " << m1 << " cnt_1: " << cnt_1 << " m2: " << m2 << " cnt_2: " << cnt_2 << endl;
		if (cnt_1 < cnt_2)
		{
			r = m2;
		}
		else
		{
			l = m1;
		}
	}
	ll ans = 1000000000000000000;
	for (ll i = l; i <= r; i++)
	{
		ll idx = i;
		ll cnt = 0;
		for (ll j = 0; j < N; j++)
		{
			if (S[j] == '1')
			{
				cnt += abs(j - idx);
				idx++;
			}
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
}
