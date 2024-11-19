#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll cnt = 0;
	string s;
	for (ll i = 0; i < 12; i++)
	{
		cin >> s;
		if (i + 1 == s.size())
		{
			cnt++;
		}
	}
	cout << cnt << endl;
}
