#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, Q;
	cin >> N >> Q;
	vector<ll> A(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	vector<tuple<ll, ll, ll>> query(Q);
	for (ll i = 0; i < Q; i++)
	{
		ll r, x;
		cin >> r >> x;
		r--;
		query[i] = make_tuple(r, x, i);
	}
	sort(query.begin(), query.end());
	const ll inf = 1000000000000000000;
	vector<ll> LIS(N, inf);
	vector<ll> ans(Q);
	ll idx = 0;
	for (ll i = 0; i < N; i++)
	{
		auto it = lower_bound(LIS.begin(), LIS.end(), A[i]);
		*it = A[i];
		while (idx < query.size() && get<0>(query[idx]) == i)
		{
			auto it = lower_bound(LIS.begin(), LIS.end(), get<1>(query[idx]));
			ans[get<2>(query[idx])] = it - LIS.begin() + (*it == get<1>(query[idx]));
			idx++;
		}
	}
	for (ll i = 0; i < Q; i++)
	{
		cout << ans[i] << endl;
	}
}
