#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<ll> C(9);
	ll min_c = 1LL << 60;
	for (ll &c : C)
	{
		cin >> c;
		min_c = min(min_c, c);
	}
	ll digit = N / min_c;
	string ans;
	ans.reserve(digit);
	for (ll i = 0; i < digit; i++)
	{
		for (ll j = 8; j >= 0; j--)
		{
			if (N - C[j] >= min_c * (digit - i - 1))
			{
				N -= C[j];
				ans.push_back('1' + j);
				break;
			}
		}
	}
	cout << ans << endl;
}
