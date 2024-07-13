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
	vector<bool> dp(K + 1, false);
	for (ll i = 0; i <= K; i++)
	{
		if (dp[i])
			continue;
		for (ll j = 0; j < N; j++)
		{
			if (i + A[j] <= K)
				dp[i + A[j]] = true;
		}
	}
	if (dp[K])
		cout << "First" << endl;
	else
		cout << "Second" << endl;
}
