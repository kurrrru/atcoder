#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll H, W;
	cin >> H >> W;
	ll sx, sy;
	cin >> sx >> sy;
	sx--;
	sy--;
	vector<string> C(H);
	for (ll i = 0; i < H; i++)
	{
		cin >> C[i];
	}
	string x;
	cin >> x;
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == 'U' && sx > 0 && C[sx - 1][sy] == '.')
		{
			sx--;
		}
		else if (x[i] == 'D' && sx < H - 1 && C[sx + 1][sy] == '.')
		{
			sx++;
		}
		else if (x[i] == 'L' && sy > 0 && C[sx][sy - 1] == '.')
		{
			sy--;
		}
		else if (x[i] == 'R' && sy < W - 1 && C[sx][sy + 1] == '.')
		{
			sy++;
		}
	}
	cout << sx + 1 << " " << sy + 1 << endl;
}
