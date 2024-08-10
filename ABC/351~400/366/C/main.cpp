#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	map<int, int> m;
	ll Q;
	cin >> Q;
	ll cnt = 0;
	while (Q--)
	{
		int t, x;
		cin >> t;
		if (t == 1)
		{
			cin >> x;
			if (m.count(x) == 0)
			{
				cnt++;
			}
			m[x]++;
		}
		else if (t == 2)
		{
			cin >> x;
			m[x]--;
			if (m[x] == 0)
			{
				m.erase(x);
				cnt--;
			}
		}
		else
		{
			cout << cnt << endl;
		}
	}
}
