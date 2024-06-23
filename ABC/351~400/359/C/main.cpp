#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(ll x, ll y)
{
	if (y >= x - 1)
		return (y);
	return (y + (x - y) / 2);
}

int main()
{
	ll sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	if (ty < sy)
	{
		swap(sy, ty);
		swap(sx, tx);
	}
	if (sx > tx)
	{
		sx = -sx - 1;
		tx = -tx - 1;
	}
	if ((sx + sy) % 2 == 0)
	{
		tx -= sx;
		sx = 0;
		ty -= sy;
		sy = 0;
	}
	else
	{
		tx -= sx;
		tx++;
		sx = 0;
		ty -= sy;
		sy = 0;
	}
	ll td = calc(tx, ty);
	cout << td << endl;
}
