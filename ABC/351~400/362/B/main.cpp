#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll xa, ya, xb, yb, xc, yc;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	xb -= xa;
	yb -= ya;
	xc -= xa;
	yc -= ya;
	if (xb * xc + yb * yc == 0 || (xb - xc) * xc + (yb - yc) * yc == 0 || xb * (xb - xc) + yb * (yb - yc) == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
