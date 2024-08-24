#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, M, X1;
	cin >> N >> M >> X1;
	vector<ll> A(M), B(M), S(M), T(M);
	vector<tuple<ll, ll, ll>> event;
	for (ll i = 0; i < M; i++)
	{
		cin >> A[i] >> B[i] >> S[i] >> T[i];
		A[i]--;
		B[i]--;
		event.push_back({T[i], 0, i});
		event.push_back({S[i], 1, i});
	}
	sort(event.begin(), event.end());
	vector<ll> delay(N), X(M);
	X[0] = X1;
	for (ll i = 0; i < 2 * M; i++)
	{
		ll j = get<2>(event[i]);
		if (get<1>(event[i]) == 0)
		{
			delay[B[j]] = max(delay[B[j]], X[j] + T[j]);
		}
		else
		{
			X[j] = max(X[j], delay[A[j]] - S[j]);
		}
	}
	for (ll i = 1; i < M; i++)
	{
		cout << X[i] << " \n"[i == M - 1];
	}
}
