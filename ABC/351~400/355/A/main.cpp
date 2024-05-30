#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	if (a == b)
		cout << -1 << endl;
	if (a == 1 && b == 2 || a == 2 && b == 1)
		cout << 3 << endl;
	if (a == 1 && b == 3 || a == 3 && b == 1)
		cout << 2 << endl;
	if (a == 2 && b == 3 || a == 3 && b == 2)
		cout << 1 << endl;
	return (0);
}
