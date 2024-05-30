#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long x;
	cin >> x;
	if (x > 0)
		cout << (x - 1) / 10 + 1 << endl;
	else if (x >= -9)
		cout << 0 << endl;
	else
	{
		x = -x;
		cout << "-" << x / 10 << endl;
	}
}