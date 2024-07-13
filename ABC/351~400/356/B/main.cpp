#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, M;
	cin >> N >> M;
	vector<ll> A(M);
	for (int i = 0; i < M; i++)
	{
		cin >> A[i];
	}
	vector<ll> B(M, 0);
	ll X;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> X;
			B[j] += X;
		}
	}
	bool ok = true;
	for (int i = 0; i < M; i++)
	{
		if (B[i] < A[i])
		{
			ok = false;
			break;
		}
	}
	cout << (ok ? "Yes" : "No") << endl;
}
