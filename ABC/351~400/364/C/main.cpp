#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, X, Y;
	cin >> N >> X >> Y;
	vector<ll> A(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end(), greater<ll>());
	vector<ll> B(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> B[i];
	}
	sort(B.begin(), B.end(), greater<ll>());
	ll AC = 0, Asum = 0;
	for (ll i = 0; i < N; i++)
	{
		AC++;
		Asum += A[i];
		if (Asum > X)
			break;
	}
	ll BC = 0, Bsum = 0;
	for (ll i = 0; i < N; i++)
	{
		BC++;
		Bsum += B[i];
		if (Bsum > Y)
			break;
	}
	cout << min(AC, BC) << endl;
}
