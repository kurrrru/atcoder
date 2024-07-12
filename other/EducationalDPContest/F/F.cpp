#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	string s, t;
	cin >> s >> t;
	ll m = s.size(), n = t.size();
	vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, 0));
	for (ll i = 1; i <= m; i++)
	{
		for (ll j = 1; j <= n; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] == t[j - 1]));
		}
	}
	string ans;
	ll i = m, j = n;
	while (i > 0 && j > 0)
	{
		if (dp[i][j] == dp[i - 1][j])
			i--;
		else if (dp[i][j] == dp[i][j - 1])
			j--;
		else
		{
			ans.push_back(s[i - 1]);
			i--;
			j--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}
