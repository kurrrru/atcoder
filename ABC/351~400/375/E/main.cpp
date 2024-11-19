#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<ll> A(N), B(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> A[i] >> B[i];
		A[i]--;
	}
	ll total = 0;
	for (ll i = 0; i < N; i++)
	{
		total += B[i];
	}
	if (total % 3 != 0)
	{
		cout << -1 << endl;
		return 0;
	}
	vector<ll> team(3, 0);
	for (ll i = 0; i < N; i++)
	{
		team[A[i]] += B[i];
	}
	if (team[0] == team[1] && team[1] == team[2])
	{
		cout << 0 << endl;
		return 0;
	}
	total /= 3;