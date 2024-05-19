#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll log2(ll n)
{
	return 63 - __builtin_clzll(n);
}

int main()
{
	ll H;
	cin >> H;
	cout << log2(H + 1) + 1<< endl;
}