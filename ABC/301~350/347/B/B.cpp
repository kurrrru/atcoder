#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int ans = 0;
	int n = (int)s.size();
	set<string> st;

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			string t = s.substr(i, j - i + 1);
			if (st.count(t))
				continue;
			st.insert(t);
			ans++;
		}
	}
	cout << ans << endl;
}