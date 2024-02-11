#include <bits/stdc++.h>
using namespace std;

vector<long long> memo(10000000, 0);

long long dp(long long n)
{
	if (n <= 1)
		return 0;
	if (n >= 10000000)
	{
		if (n & 1)
			return (dp(n >> 1) + dp((n + 1) >> 1) + n);
		else
			return (dp(n >> 1) * 2 + n);
	}
	else
	{
		if (memo[n] > 0)
			return (memo[n]);
		else
		{
			if (n & 1)
				return (memo[n] = dp(n >> 1) + dp((n + 1) >> 1) + n);
			else
				return (memo[n] = dp(n >> 1) * 2 + n);
		}
	}
}


int main()
{
	long long N;
	cin >> N;
	cout << dp(N) << endl;
}
