#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, K;
	cin >> N >> K;
	vector<ll> A(N);
	for (ll i = 0; i < N; i++)
		cin >> A[i];
	vector<ll> cnt(1000001);
	for (ll i = 0; i < N; i++)
		cnt[A[i]]++;
	vector<ll> cnt2(1000001);
	for (ll i = 1; i < 1000001; i++)
	{
		for (ll j = i; j < 1000001; j += i)
		{
			cnt2[i] += cnt[j];
		}
	}
	vector<ll> memo(1000001);
	for (ll i = 1; i < 1000001; i++)
	{
		if (cnt2[i] < K)
			continue;
		for (ll j = i; j < 1000001; j += i)
		{
			memo[j] = max(memo[j], i);
		}
	}
	for (ll i = 0; i < N; i++)
	{
		cout << memo[A[i]] << endl;
	}
}
