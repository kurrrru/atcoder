#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	string s;
	ll ans = 0;
	for (ll i = 0; i < N; i++)
	{
		cin >> s;
		if (s == "Takahashi")
			ans++;
	}
	cout << ans << endl;
}
