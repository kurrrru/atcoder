#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, M;
	cin >> N >> M;
	vector<ll> A(N), B(M);
	for (ll i = 0; i < N; i++)
		cin >> A[i];
	for (ll i = 0; i < M; i++)
		cin >> B[i];
	B.push_back(201);
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	ll j = 0;
	for (int i = 0; i <= M; i++)
	{
		if (j >= N)
			break;
		if (A[j] < B[i])
			j++;
		if (j < N && A[j] < B[i])
		{
			cout << "Yes" << endl;
			return (0);
		}
	}
	cout << "No" << endl;
	return (0);
}
