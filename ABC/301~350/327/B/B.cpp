#include <bits/stdc++.h>
using namespace std;

long long	power(long long base, long long exp) {
    if (!exp) return 1;
    if (exp & 1) return  power(base, exp - 1) * base;
    else return power(base * base, exp >> 1);
}

int main()
{
	long long	B;
	cin >> B;
	for (long long n = 1; n < 16; n++)
	{
		if (power(n, n) == B)
		{
			cout << n << endl;
			return (0);
		}
	}
	cout << -1 << endl;
	return (0);
}