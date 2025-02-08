#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<ll> K(N);
	vector<vector<ll>> A(N);
	vector<map<ll, ll>> B(100010);
	for (ll i = 0; i < N; i++)
	{
		cin >> K[i];
		A[i].resize(K[i]);
		for (ll j = 0; j < K[i]; j++)
		{
			cin >> A[i][j];
			if (B[A[i][j]].count(i) == 0)
			{
				B[A[i][j]][i] = 1;
			}
			else
			{
				B[A[i][j]][i]++;
			}
		}
	}
	vector<vector<ll>> cnt(N, vector<ll>(N, 0));
	for (ll i = 0; i < 100010; i++)
	{
		for (auto p = B[i].begin(); p != B[i].end(); p++)
		{
			for (auto q = p; q != B[i].end(); q++)
			{
				cnt[p->first][q->first] += p->second * q->second;
			}
		}
	}
	double ans = 0;
	for (ll i = 0; i < N; i++)
	{
		for (ll j = i + 1; j < N; j++)
		{
			ans = max(ans, (double)cnt[i][j] / K[i] / K[j]);
		}
	}
	cout << fixed << setprecision(10);
	cout << ans << endl;
}
