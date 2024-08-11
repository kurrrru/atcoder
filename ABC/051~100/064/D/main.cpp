#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	string S;
	cin >> N >> S;
	vector<ll> dp(N + 1, 0);
	for (ll i = 0; i < N; ++i)
	{
		if (S[i] == '(')
		{
			dp[i + 1] = dp[i] + 1;
		}
		else
		{
			dp[i + 1] = dp[i] - 1;
		}
	}
	ll min_dp = *min_element(dp.begin(), dp.end());
	for (ll i = 0; i < dp[0] - min_dp; ++i)
	{
		cout << '(';
	}
	cout << S;
	for (ll i = 0; i < dp[N] - min_dp; ++i)
	{
		cout << ')';
	}
	cout << endl;
}
