#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll H, W, D;
	cin >> H >> W >> D;
	vector<string> S(H);
	for (ll i = 0; i < H; i++)
		cin >> S[i];
	ll ans = 0;
	for (ll x1 = 0; x1 < H; x1++)
	{
		for (ll y1 = 0; y1 < W; y1++)
		{
			for (ll x2 = 0; x2 < H; x2++)
			{
				for (ll y2 = 0; y2 < W; y2++)
				{
					if (S[x1][y1] == '#' || S[x2][y2] == '#' || (x1 == x2 && y1 == y2))
						continue;
					ll cnt = 0;
					for (ll x = 0; x < H; x++)
					{
						for (ll y = 0; y < W; y++)
						{
							if (S[x][y] == '#')
								continue;
							if (abs(x - x1) + abs(y - y1) <= D || abs(x - x2) + abs(y - y2) <= D)
								cnt++;
						}
					}
					ans = max(ans, cnt);
				}
			}
		}
	}
	cout << ans << endl;
}
