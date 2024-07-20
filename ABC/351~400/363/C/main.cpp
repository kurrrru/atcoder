#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_k_palindrome(string S, ll K)
{
	ll N = S.size();
	for (ll i = 0; i <= N - K; ++i)
	{
		bool flag = true;
		for (ll j = 0; j < K / 2; ++j)
		{
			if (S[i + j] != S[i + K - j - 1])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			return true;
	}
	return false;
}

int main()
{
	ll N, K;
	string S;
	cin >> N >> K >> S;
	sort(S.begin(), S.end());
	ll ans = 0;
	do
	{
		if (!is_k_palindrome(S, K))
			ans++;
	} while (next_permutation(S.begin(), S.end()));
	cout << ans << endl;
}
