#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	string S;
	cin >> S;
	ll ans = 0;
	for (ll i = 1; i < N - 1; i++)
	{
		if (S[i - 1] == '#' && S[i] == '.' && S[i + 1] == '#')
		{
			ans++;
		}
	}
	cout << ans << endl;
}
