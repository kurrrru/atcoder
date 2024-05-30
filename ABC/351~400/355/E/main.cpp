#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, L, R;
	cin >> N >> L >> R;
	ll ans = 0;
	while (L <= R)
	{
		ll i = 0, j = L;
		while (j % 2 == 0 && (j + 2) * (1 << i) - 1 <= R)
		{
			j /= 2;
			i++;
		}
		L = (j + 1) * (1 << i);
		cout << "? " << i << " " << j << endl;
		ll res;
		cin >> res;
		ans += res;
	}
	cout << "! " << ans % 100 << endl;
}
