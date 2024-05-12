#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll m;
	string s;
	cin >> m >> s;
	reverse(s.begin(), s.end());
	int n = stoi(s, nullptr, 2);
	char ans[100005] = {};
	int idx = 0, trigger = 1;
	for (int i = m - 1; i >= 0; i--)
	{
		if (((n >> i) & 1) == trigger)
		{
			if (trigger == 1)
			{
				for (int j = 0; j <= i; j++)
				{
					ans[idx++] = 'A';
				}
			}
			else
			{
				for (int j = 0; j <= i; j++)
				{
					ans[idx++] = 'B';
				}
			}
			trigger = 1 - trigger;
		}
	}
	cout << idx << endl;
	cout << ans << endl;

}