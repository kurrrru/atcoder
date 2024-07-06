#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	string S, T;
	cin >> S >> T;
	S += "..";
	T += "..";
	N += 2;
	queue<pair<string, ll>> q;
	set<string> visited;
	q.push({S, 0});
	visited.insert(S);
	while (!q.empty())
	{
		auto [s, d] = q.front();
		// cout << s << " " << d << endl;
		q.pop();
		if (s == T)
		{
			cout << d << endl;
			return 0;
		}
		auto it = visited.lower_bound(s);
		// if (it != visited.end() && it->find(s) != string::npos)
		// 	continue;
		for (ll i = 0; i < N - 1; i++)
		{
			if (s[i] != '.' || s[i + 1] != '.')
				continue;
			for (ll j = 0; j < N - 1; j++)
			{
				string t = s;
				if (t[j] == '.' || t[j + 1] == '.')
					continue;
				swap(t[i], t[j]);
				swap(t[i + 1], t[j + 1]);
				if (visited.find(t) == visited.end())
				{
					q.push({t, d + 1});
					visited.insert(t);
				}
			}
		}
	}
	cout << -1 << endl;
}
