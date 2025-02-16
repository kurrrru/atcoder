#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n, m;
	cin >> n >> m;
	int cnt = 0;
	set<pair<int, int>> st;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		if (u == v || st.count({u, v}) || st.count({v, u}))
		{
			cnt++;
			continue;
		}
		if (!st.count({u, v}) && !st.count({v, u}))
		{
			st.insert({u, v});
			st.insert({v, u});
		}
	}
	cout << cnt << endl;
}
