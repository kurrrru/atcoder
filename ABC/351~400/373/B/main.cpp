#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	string s;
	cin >> s;
	ll cnt = 0;
	ll last = 0;
	for (ll i = 0; i < s.size(); i++)
	{
		if (s[i] == 'A')
		{
			last = i;
		}
	}
	for (char c = 'B'; c <= 'Z'; c++)
	{
		for (ll i = 0; i < s.size(); i++)
		{
			if (s[i] == c)
			{
				cnt += abs(last - i);
				last = i;
				break;
			}
		}
	}
	cout << cnt << endl;
}
