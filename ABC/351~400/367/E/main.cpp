#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, K;
	cin >> N >> K;
	vector<ll> X(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> X[i];
		X[i]--;
	}
	vector<ll> A(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	vector<ll> tmp(N);
	while (K > 0)
	{
		if (K & 1)
		{
			for (ll i = 0; i < N; ++i)
			{
				tmp[i] = A[X[i]];
			}
			swap(A, tmp);
		}
		for (ll i = 0; i < N; ++i)
		{
			tmp[i] = X[X[i]];
		}
		swap(X, tmp);
		K >>= 1;
	}
	for (ll i = 0; i < N; i++)
	{
		cout << A[i] << " \n"[i == N - 1];
	}
}
