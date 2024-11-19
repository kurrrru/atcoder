#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, M, K;
	cin >> N >> M >> K;
	vector<ll> A(N);
	vector<pair<ll, ll>> B(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> A[i];
		B[i] = { A[i], i };
	}
	if (N == M)
	{
		for (ll i = 0; i < N; i++)
		{
			cout << 0 << " \n"[i + 1 == N];
		}
		return 0;
	}
	sort(B.begin(), B.end(), greater<pair<ll, ll>>());
	ll sum = accumulate(A.begin(), A.end(), 0LL);
	K -= sum;
	vector<ll> acc(N + 1, 0);
	for (ll i = 0; i < N; i++)
	{
		acc[i + 1] = acc[i] + B[i].first;
	}
	vector<ll> ans(N);
	for (ll i = 0; i < M; i++)
	{
		ll right = K;
		ll left = -1;
		while (right - left > 1)
		{
			ll mid = (right + left) / 2;
			auto it = lower_bound(B.begin(), B.end(), make_pair(mid + B[i].first, 1ll << 30), greater<pair<ll, ll>>());
			ll j = it - B.begin();
			ll width = M - j + 1;
			ll par = acc[M + 1] - acc[j];
			// cout << "mid = " << mid << ", j = " << j << ", width = " << width << ", par = " << par << endl;
			bool ok = ((mid + B[i].first) * width - par >= K);
			if (ok)
			{
				right = mid;
			}
			else
			{
				left = mid;
			}
		}
		ans[B[i].second] = right;
	}
	for (ll i = M; i < N; i++)
	{
		if (B[i].first + K < B[M - 1].first)
		{
			ans[B[i].second] = -1;
			continue;
		}
		ll right = K;
		ll left = -1;
		while (right - left > 1)
		{
			ll mid = (right + left) / 2;
			auto it = lower_bound(B.begin(), B.end(), make_pair(mid + B[i].first, 1ll << 30), greater<pair<ll, ll>>());
			ll j = it - B.begin();
			ll width = M - j;
			ll par = acc[M] - acc[j];
			// cout << "mid = " << mid << ", j = " << j << ", width = " << width << ", par = " << par << endl;
			bool ok = ((mid + B[i].first) * width - par >= K - mid);
			if (ok)
			{
				right = mid;
			}
			else
			{
				left = mid;
			}
		}
		ans[B[i].second] = right;
	}

	for (ll i = 0; i < N; i++)
	{
		cout << ans[i] << " \n"[i + 1 == N];
	}
}
