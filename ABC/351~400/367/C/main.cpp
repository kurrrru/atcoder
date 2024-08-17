#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cnt = 0;

void dfs(ll pos, ll N, ll K, const vector<ll> &R, vector<ll> &ans)
{
	if (pos == N)
	{
		ll sum = 0;
		for (ll i = 0; i < N; i++)
		{
			sum += ans[i];
		}
		if (sum % K != 0)
		{
			return ;
		}
		for (ll i = 0; i < N; i++)
		{
			cout << ans[i] << " \n"[i == N - 1];
		}
		cnt++;
		return ;
	}
	for (ll i = 1; i <= R[pos]; i++)
	{
		ans[pos] = i;
		dfs(pos + 1, N, K, R, ans);
	}
}

int main()
{
	ll N, K;
	cin >> N >> K;
	vector<ll> R(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> R[i];
	}
	vector<ll> ans(N);
	dfs(0, N, K, R, ans);
	if (cnt == 0)
	{
		cout << endl;
	}
}
