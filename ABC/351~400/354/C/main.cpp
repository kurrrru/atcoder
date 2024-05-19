#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<tuple<ll, ll, ll>> cards;
	for (ll i = 0; i < N; i++)
	{
		ll a, b;
		cin >> a >> b;
		cards.push_back(make_tuple(a, -b, i));
	}
	sort(cards.begin(), cards.end());
	vector<ll> ans;
	vector<ll> min_cost(N, 1e9);
	min_cost[N - 1] = get<1>(cards[N - 1]);
	for (ll i = N - 2; i >= 0; i--)
	{
		min_cost[i] = max(min_cost[i + 1], get<1>(cards[i]));
	}
	for (ll i = 0; i < N - 1; i++)
	{
		if (get<1>(cards[i]) >= min_cost[i + 1])
		{
			ans.push_back(get<2>(cards[i]));
		}
	}
	ans.push_back(get<2>(cards[N - 1]));

	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (ll i = 0; i < ans.size(); i++)
	{
		cout << ans[i] + 1;
		if (i < ans.size() - 1)
		{
			cout << " ";
		}
	}
	cout << endl;
}