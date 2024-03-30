#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	long long x = 0, y = 0;

	for (int i = 0; i < 60; i++)
	{
		if (c & (1LL << i))
		{
			if (a > b)
			{
				x += (1LL << i);
				a--;
			}
			else
			{
				y += (1LL << i);
				b--;
			}
		}
	}
	if (a != b)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < 60; i++)
	{
		if (a == 0)
			break;
		if (c & (1LL << i))
			continue;
		x += (1LL << i);
		y += (1LL << i);
		a--;
	}
	if (a != 0)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << x << " " << y << endl;
}