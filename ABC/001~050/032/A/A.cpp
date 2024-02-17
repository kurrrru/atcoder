#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, n;
	cin >> a >> b >> n;
	int l = lcm(a, b);
	cout << ((n - 1) / l + 1) * l << endl;
}