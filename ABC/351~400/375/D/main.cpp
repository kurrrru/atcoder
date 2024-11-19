#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	string S;
	cin >> S;
	ll N = S.size();
	ll cnt[26] = {};
	ll cnt2[26] = {};
	ll ans = 0;
	for (ll i = 0; i < N; i++)
	{
		ans += cnt2[S[i] - 'A'];
		for (ll j = 0; j < 26; j++)
		{
			cnt2[j] += cnt[j];
		}
		cnt[S[i] - 'A']++;
	}
	cout << ans << endl;
}
