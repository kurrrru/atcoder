#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<ll> A(N);
	for (ll i = 0; i < N; i++)
		cin >> A[i];
	priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
	for (ll i = 0; i < N - 1; i++)
		pq.push({A[i] + A[i + 1], i, i + 1});
	ll ans = 0;
	for (ll i = 0; i < N; i++)
		ans += A[i];
	set<ll> used;
	for (ll i = 0; i < N; i++)
		used.insert(i);
	while (!pq.empty())
	{
		auto [c, i, j] = pq.top();
		pq.pop();
		if (c >= 0)
			break;
		if (used.count(i) == 0 || used.count(j) == 0)
			continue;
		ans -= c;
		used.erase(i);
		used.erase(j);
		auto before_i_it = used.lower_bound(i);
		auto after_j_it = used.upper_bound(j);
		if (before_i_it != used.begin() && after_j_it != used.end())
		{
			auto before_i = *prev(before_i_it);
			auto after_j = *after_j_it;
			pq.push({A[before_i] + A[after_j], before_i, after_j});
		}
	}
	cout << ans << endl;
}
