/*
Tの文字でSに含まれないものがある場合、ans=0
Tの文字

0314321
3131

*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	string S, T;
	cin >> N >> S >> T;
	ll l = 0LL, r = 1000000000000000000LL;
	vector<vector<ll> > idx(128, vector<ll>());
	vector<ll> cnt(128, 0);
	for (ll i = 0; i < S.size(); i++)
	{
		idx[S[i]].push_back(i);
		cnt[S[i]]++;
	}
	while (r - l > 1)
	{
		ll mid = (l + r) / 2;
		ll n = 1;
		ll now_idx = 0;
		bool ok = false;
		for (ll i = 0; i < T.size(); i++)
		{
			ll k = mid;
			if (cnt[T[i]] == 0)
			{
				cout << 0 << endl;
				return 0;
			}
			auto id = lower_bound(idx[T[i]].begin(), idx[T[i]].end(), now_idx);
			if (k < idx[T[i]].end() - id)
			{
				if (k > 0)
				{
					now_idx = (*(id + k - 1) + 1) % S.size();
					if (now_idx == 0 && i != T.size() - 1)
						n++;
				}
				continue;
			}
			k -= idx[T[i]].end() - id;
			n += k / cnt[T[i]];
			k %= cnt[T[i]];
			if (k == 0)
			{
				now_idx = (idx[T[i]][cnt[T[i]] - 1] + 1) % S.size();
				if (now_idx == 0 && i != T.size() - 1)
					n++;
			}
			else if (k > 0 && i != T.size() - 1)
			{
				n++;
				now_idx = (idx[T[i]][k - 1] + 1) % S.size();
			}	
		}
		ok = (n <= N);
		if (ok)
			l = mid;
		else
			r = mid;
	}
	cout << l << endl;

}