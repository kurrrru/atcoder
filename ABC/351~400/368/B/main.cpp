#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<ll> A(N);
	for (ll i = 0; i < N; i++)
		cin >> A[i];
	ll cnt = 0;
	while (1)
	{
		sort(A.begin(), A.end(), greater<ll>());
		if (A[1] > 0)
		{
			A[0]--;
			A[1]--;
			cnt++;
		}
		else
		{
			cout << cnt << endl;
			return 0;
		}
	}
}
