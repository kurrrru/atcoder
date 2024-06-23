#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<ll> H(N);
	for (ll i = 0; i < N; i++)
		cin >> H[i];
	vector<ll> dp(N);
	dp[0] = H[0] + 1;
	stack<ll> st;
	st.push(0);
	for (ll i = 1; i < N; i++)
	{
		if (H[i] <= H[i - 1])
		{
			dp[i] = dp[i - 1] + H[i];
			st.push(i);
		}
		else
		{
			while (!st.empty() && H[st.top()] < H[i])
				st.pop();
			if (st.empty())
			{
				dp[i] = H[i] * (i + 1) + 1;
				// cout << i << " " << H[i] << " " << dp[i] << endl;
				st.push(i);
			}
			else
			{
				dp[i] = dp[st.top()] + H[i] * (i - st.top());
				// cout << st.top() << " " << i << " " << H[i] << " " << dp[i] << endl;
				st.push(i);
			}
		}
	}
	for (ll i = 0; i < N; i++)
		cout << dp[i] << " \n"[i == N - 1];
}
