#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, M;
	cin >> N >> M;
	vector<ll> A(M);
	for (ll i = 0; i < M; i++)
		cin >> A[i];
	unordered_map<ll, ll> mp;
	for (ll i = 0; i < N; i++)
		mp[i + 1] = 0;
	for (ll i = 0; i < M; i++)
		mp[A[i]]++;
	vector<ll> ans;
	for (ll i = 1; i <= N; i++)
	{
		if (mp[i] == 0)
		{
			ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	for (ll i = 0; i < ans.size(); i++)
		cout << ans[i] << " \n"[i == ans.size() - 1];
	if (ans.size() == 0)
		cout << endl;
}
